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

int main(int argc, char *argv[])
{
	key_t key;
	int ret;

	key = ftok("/tmp", 11);
	if (key < 0)
	{
		printf("ftok failed!\n");
		return -1;
	}
	printf("key = %0x\n", key);

	/*ret = msgget(1, IPC_CREAT | IPC_EXCL | 0666);*/
	ret = msgget(1, IPC_CREAT | 0666);
	if (ret < 0)
	{
		printf("msgget failed!\n");
		perror("msgget");
		return -1;
	}

	printf("msgget success!\n");
	printf("ret = %d\n", ret);

	int size;
	size = msgsnd(ret, argv[1], strlen(argv[1]), 0);
	if (size < 0)
	{
		return -1;
	}
	printf("size = %d\n", size);
	return 0;
}
