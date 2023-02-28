#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "gen.h"

/* put x + y into a byte */
uint8_t combine_into_bytes(uint8_t x, uint8_t y, uint8_t first_shift)
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

void create_iphdr_ipv4(struct iphdr *hdr, struct bit_hold, uint16_t length, uint16_t ident, uint8_t ttl, uint8_t proto,
		       uint16_t csum, uint32_t source, uint32_t dest)
{ /* TODO: write code */}
