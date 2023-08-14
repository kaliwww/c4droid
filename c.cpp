#include <stdio.h>

/*socket-bind-listen-accept*/
#include <sys/types.h>
#include <sys/socket.h>
/*memset*/
#include <string.h>
/*sockaddr_in结构体*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
/*htons*/
#include <arpa/inet.h>
/*inet_addr*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
/*close*/
#include <unistd.h>
/*exit*/
#include <stdlib.h>

int main(){
	int s=1;
	if ((s=socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket failed");
		exit(-1);
		}
		
		
		
		
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(6552);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	socklen_t add=sizeof(addr);
	if (connect(s,(struct sockaddr *)&addr,add)){
		perror("connect failed");
		exit(-1);
		}}
	