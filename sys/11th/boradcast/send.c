#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <shadow.h>
#include <grp.h>
#include <time.h>
#include <sys/utsname.h>
#include <dirent.h>
#include <glob.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define PORT 8899

//send udp
int main(int argc, char *argv[])
{
	int sd;
	int ret;
	//1 创建套接子
	sd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sd < 0)
	{
		perror("socket");
		return -1;
	}
	int val = 1;
	
	ret = setsockopt(sd, SOL_SOCKET, SO_BROADCAST, &val, sizeof(val));
	if (ret == -1)
	{
		printf("setsockopt failed!\n");
		return -1;
	}

	struct sockaddr_in to;
	to.sin_family = AF_INET;
	to.sin_port = htons(PORT);
	to.sin_addr.s_addr = inet_addr("2.2.2.255");

	int fd;
	char ch;
	fd = open("./passwd", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return -1;
	}
	while(1)
	{
		/*printf("ch = %c\n", ch);*/
		ret = read(fd, &ch, 1);
		if (ret <= 0)
		{
			lseek(fd, 0, SEEK_SET);
			continue;
		}
		/*printf("%c", ch);*/
		printf("%d", ret);
		ret = sendto(sd, &ch, 1, 0, (struct sockaddr *)&to, sizeof(to));
		if (ret < 0)
		{
			printf("sendto failed!\n");
			return -1;
		}
		usleep(10000);
	}
	close(sd);
	return 0;
}









