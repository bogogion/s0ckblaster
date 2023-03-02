#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

/* used for bit values */

struct bit_hold
{
	uint8_t ver  : 4;
	uint8_t len  : 4;

	uint8_t flag : 3;
	uint16_t off : 13;
};

uint8_t combine_into_byte(uint8_t x, uint8_t y, uint8_t first_shift);
uint16_t combine_into_flag_off(uint8_t x, uint16_t y);
uint16_t calc_csum(uint16_t *ptr, int nbytes);

/* TODO: create these properly */
void create_iphdr_ipv4(struct iphdr *hdr, struct bit_hold, uint16_t length, uint16_t ident, uint8_t ttl, uint8_t proto,
		       uint32_t source, uint32_t dest);
void create_iphdr_ipv6(struct iphdr *hdr);
void create_udp_packet(struct udphdr *hdr, struct iphdr *ihdr, uint16_t sport, uint16_t dport, uint16_t len, int csum_bool);
