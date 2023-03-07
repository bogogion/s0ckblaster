#include <netinet/ip.h>


/* Bit hold for ipheader */
struct ip_bit_hold
{
	uint8_t ver : 4;	
	uint8_t ihl : 4;

	uint8_t dscp : 6;
	uint8_t ecn : 2;

	uint8_t flag : 3;
	uint16_t off : 13;
};

/* Complete header */
struct s_iphdr4
{
	uint8_t ver_ihl;
	uint8_t dscp_ecn;

	uint16_t len;
	uint16_t ident;
	uint16_t flag_off;
	
	uint8_t ttl;
	uint8_t prot;
	
	uint16_t check;

	uint32_t src;
	uint32_t dest;
};
