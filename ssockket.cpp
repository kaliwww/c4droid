

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
	char d[200];
	int a=0;
	printf("请输入端口：");
	scanf("%d",&a);
	
	
	int s=1;
	if ((s=socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket failed");
		exit(-1);
		}
		
		
		
		
	struct sockaddr_in saddr;
	//memset(&saddr,0,sizeof(saddr));
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(a);
	saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	socklen_t sadd=sizeof(saddr);
	
	if (bind(s,(struct sockaddr *)&saddr,sadd)==-1){
		perror("bind failed");
		exit(-1);
		
		}
	
		
	if (listen(s,5)==-1){
		perror("listen failed");
		exit(-1);
		
		}
	
	
	
	
	
	struct sockaddr_in caddr;
	socklen_t cadd=sizeof(caddr);
	if (accept(s,(struct sockaddr *)&caddr,&cadd)==-1){
		perror("accept failed");
		exit(-1);
		}
	
	printf("服务端连接成功");
	
	
	while (1)
    {
        char bu[128] = {0};
        //发
        printf("input  > ");
        scanf("%s", bu);
        send(s, bu, 128,0);
        if (strcmp(bu,"quit")==0)
        {
            //关闭文件描述符
            close(s);
            break;
        }

        //收
        memset(bu, 0, sizeof(bu));
        printf("服务器 > ");
        fflush(stdout);
	    recv(s, bu, 128,0);
        printf("%s\n", bu);
        if (strcmp(bu,"quit")==0)
        {
            //关闭文件描述符
            close(s);
            break;}}
	
	
	
	
	
	}
