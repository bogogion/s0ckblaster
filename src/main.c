#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include "gen/gen.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


int main()
{
	/* TODO: create main loop */
	
	printf("+-----------+\n|s0ckblaster|\n+---v0.0.1--+\n");

	unsigned char data[9];

	data[0] = 1;

	unsigned char packet[20 + 8 + 9];

	unsigned char *ptr = packet; 
	struct ip_bit_hold bhold;
	bhold.ver = 4;
	bhold.ihl = 5;
	
	bhold.dscp = 0;
	bhold.ecn = 0;

	bhold.flag = 2;
	bhold.off = 0;
	
	uint32_t src,dest;

	src = inet_addr("127.0.0.1");
	dest = inet_addr("127.0.0.1");

	struct s_iphdr4 hdr;
	struct udphdr uhdr;

	uint16_t length = 5*4 + 8 + 9;

	create_iphdr_ipv4(&hdr,bhold,length,0,64,0x11,src,dest);
	create_udp_packet(&uhdr, NULL, 5805, 5805, 17, 0);

	memcpy(ptr, &hdr, 5*4);
	memcpy(ptr+(5*4), &uhdr, 8);
	memcpy(ptr+(5*4)+8, &data ,9);

	for(int i = 0; i < 37; i++)
	{
		//printf("0x%x ", packet[i]);
		printf("\n"BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(packet[i]));
	}
	printf("\n");
	return 0;
}
