#ifndef _IP_VALIDATOR_H_
#define _IP_VALIDATOR_H_

#ifdef __cplusplus
extern "C" {
#endif

int is_valid_ip_v1(const char *addr);
int is_valid_ip_v2(const char *addr);
int is_valid_ip_v3(const char *addr);

#ifdef __cplusplus
}
#endif

#endif // _IP_VALIDATOR_H_
