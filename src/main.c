#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include "gen/gen.h"

int main()
{
	/* TODO: create main loop */
	printf("sup dawg\n");
	
	unsigned char data[9];

	unsigned char packet[sizeof(struct iphdr) + sizeof(struct udphdr) + 9];

	struct bit_hold bhold;
	bhold.ver = 1;
	bhold.len = 5;
	
	bhold.flag = 2;
	bhold.off = 0;
	
	uint32_t src,dest;

	src = inet_addr("127.0.0.1");
	dest = inet_addr("127.0.0.1");

	struct iphdr hdr;
	struct udphdr uhdr;

	create_iphdr_ipv4(&hdr,bhold,100,123,15,1,src,dest);
	create_udp_packet(&uhdr, NULL, 5805, 5805, 17, 0);

	


	return 0;
}
