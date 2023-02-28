#include <netinet/ip.h>
#include <netinet/tcp.h>

/* used for bit values */

struct bit_hold
{
	uint8_t ver  : 4;
	uint8_t len  : 4;

	uint8_t dscp : 6;
	uint8_t enc  : 2;

	uint8_t flag : 3;
	uint16_t off : 13;
};

uint8_t combine_into_bytea(uint8_t x, uint8_t y, uint8_t first_shift);
uint16_t combine_into_flag_off(uint8_t x, uint16_t y);

/* TODO: create these properly */
void create_iphdr_ipv4(struct iphdr *hdr, struct bit_hold, uint16_t length, uint16_t ident, uint8_t ttl, uint8_t proto,
		       uint16_t csum, uint32_t source, uint32_t dest);
void create_iphdr_ipv6(struct iphdr *hdr);
