#ifndef __OS_SOCKET_BSD_H__
#define __OS_SOCKET_BSD_H__

#include <arpa/inet.h>
#include <sys/socket.h> 
#include <unistd.h>

/*osa_socket() address family value*/
#define OSA_AF_INET  AF_INET     //ipv4
#define OSA_AF_INET6 AF_INET6    //ipv6
/*osa_socket() type value*/
#define OSA_SOCK_STREAM SOCK_STREAM
#define OSA_SOCK_DGRAM  SOCK_DGRAM
/*osa_socket() protocol value*/
#define OSA_IPPROTO_TCP IPPROTO_TCP
#define OSA_IPPTOTO_UDP IPPTOTO_UDP

/*osa_shutdown() howto value*/
#define OSA_SHUT_RD    SHUTRD
#define OSA_SHUT_WR    SHUTWR
#define OSA_SHUT_RDWR  SHUT_RDWR

uint32_t osa_htonl(uint32_t hostlong);
uint16_t osa_htons(uint16_t hostshort);
uint32_t osa_ntohl(uint32_t netlong);
uint16_t osa_ntohs(uint16_t netshort);
/*
	struct sockaddr_in
	{
	    sa_family_t     sin_family;   //Address Family
	    uint16_t        sin_port;     //port,16 bits
	    struct in_addr  sin_addr;     //ip, 32bits
	    char            sin_zero[8];  
	};
	struct in_addr
	{
    	in_addr_t  s_addr;  //ip, 32bits
	};

	struct sockaddr
	{
	    sa_family_t  sin_family;   //Address Family
	    char         sa_data[14];  //IP and port
	};

*/
int osa_socket(int af, int type, int protocol);
int osa_bind(int sock, struct sockaddr *addr, socklen_t addrlen);
int osa_connect(int sock, struct sockaddr *serv_addr, socklen_t addrlen);
int osa_listen(int sock, int backlog);
int osa_accept(int sock, struct sockaddr *addr, socklen_t *addrlen);
int osa_socket_close(int sockfd);
int osa_shutdown(int sock, int howto);

#endif