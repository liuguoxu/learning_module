#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
    int sock_send_fd;
    struct sockaddr_in addr;
   
    memset(&addr,0,sizeof(struct sockaddr_in));
    
    if ((sock_send_fd = socket(AF_INET, SOCK_DGRAM,0)) < 0)
    {
        perror("socket create error\n");
        exit(1);
    }

	addr.sin_family = AF_INET;
    addr.sin_port = htons(32145);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (addr.sin_addr.s_addr == INADDR_NONE)
	{
       printf("Incorrect ip address!\n");
       close(sock_send_fd);
     exit(1);
     }

   char  *buff = "qwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufiouefjoidsaufuwepofjkosdjvaoijdspofiewurpr-32SD902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQJRKWOEQURqwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufioufjoidsaufuwepofjkosdjvaoijdspofiewurpr-32r902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQWJRKWOEQURqwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufifjoidsaufuwepofjkosdjvaoijdspofiewurpr-32r902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQW";
	int a =5;
   while (a)
   {
        int n;
		printf("buf : %s\n", buff);
       n = sendto(sock_send_fd , buff, strlen(buff), 0, (struct sockaddr *)&addr, sizeof(addr));
       if (n < 0)
       {
            perror("sendto");
            close(sock_send_fd);
            break;
        }
		printf("send success\n");	    
		   a--; 
	}
}
