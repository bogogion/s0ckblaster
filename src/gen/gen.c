#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "gen.h"

/* put x + y into a byte */
uint8_t combine_into_byte(uint8_t x, uint8_t y, uint8_t first_shift)
{
	uint8_t temp;
	
	/* Add four bits from x and shift over by first_shift, then do OR on last four bits to put into final bytes */
	temp = (x << first_shift) | y;
	return temp;
}

uint16_t combine_into_flag_off(uint8_t x, uint16_t y)
{
	uint16_t temp;

	temp = (x << 13) | y;
	return temp;
}

uint16_t calc_csum(uint16_t *ptr,int nbytes) 
{
	register long sum;
	unsigned short oddbyte;
	register short answer;

	sum=0;
	while(nbytes) {
		sum += *ptr++;
		nbytes-=2;
	}

	sum = (sum>>16)+(sum & 0xffff);
	sum = sum + (sum>>16);
	answer=(short)~sum;
	
	return(answer);
}

void create_iphdr_ipv4(struct iphdr *hdr, struct bit_hold bit_hold, uint16_t length, uint16_t ident, uint8_t ttl, uint8_t proto,
		       uint32_t source, uint32_t dest)
{
	/* Fill in values and properly format combined bytes */
	hdr->version = bit_hold.ver;
	hdr->ihl = bit_hold.len;
	hdr->tot_len = length;
	hdr->id = ident;
	hdr->frag_off = combine_into_flag_off(bit_hold.flag, bit_hold.off);
	hdr->protocol = proto;
	hdr->check = 0;
	hdr->saddr = source;
	hdr->daddr = dest;

	hdr->check = calc_csum((uint16_t *) hdr, (4 * hdr->ihl));
}

void create_udp_packet(struct udphdr *hdr, struct iphdr *ihdr, uint16_t sport, uint16_t dport, uint16_t len, int csum_bool)
{
	/* Check if to create checksum*/
	if(!csum_bool)
	{
		hdr->source = sport;
		hdr->dest   = dport;
		hdr->len    = len;
		hdr->check  = 0;
	} else
	{
		printf("Checksum currently unavaible, will be needed for IPv6\n");
	}
}
