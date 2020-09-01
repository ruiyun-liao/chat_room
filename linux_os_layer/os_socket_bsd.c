#include "os_socket_bsd.h"

uint32_t osa_htonl(uint32_t hostlong)
{
	return htonl(hostlong);
}

uint16_t osa_htons(uint16_t hostshort)
{
	return htons(hostshort);
}

uint32_t osa_ntohl(uint32_t netlong) 
{
	return ntohl(netlong);
}

uint16_t osa_ntohs(uint16_t netshort)
{
	return ntohs(netshort);
}


int osa_socket(int af, int type, int protocol)
{
	return socket(af, type, protocol);
}
int osa_bind(int sock, struct sockaddr *addr, socklen_t addrlen)
{
	return bind(sock, addr, addrlen);
}
int osa_connect(int sock, struct sockaddr *serv_addr, socklen_t addrlen)
{
	return connect(sock, serv_addr, addrlen);
}
int osa_listen(int sock, int backlog)
{
	return listen(sock, backlog);
}
int osa_accept(int sock, struct sockaddr *addr, socklen_t *addrlen)
{
	return accept(sock, addr, addrlen);
}
int osa_socket_close(int sockfd)
{
	return close(sockfd);
}
int osa_shutdown(int sock, int howto)
{
	return shutdown(sock, howto);
}





