/*****************************************************************
BUFSIZ作用:
	程序输出时，为减轻系统负担，可以先将需要输出的字符保存起来，
即放入内存缓冲。
	当达到输出条件时：行缓冲遇到换行符，块缓冲遇到写满缓存，或
用户强制fflush；才进行写文件动作。BUFSIZ为系统默认的缓冲区大小。

BUFSIZ使用:
	默认BUFSIZ = 8192字节
	#include <stdio.h> (引入头文件即可)
	setbuf(stdout, buf); (修改默认缓冲大小)
	setbuf()函数的第二个参数取值可以为null，此时标准输出不需要进行
缓冲，程序运行速度变慢，系统负担变大。
*****************************************************************/
#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

int main(void)
{
	//默认缓冲区大小
	printf("BUFSIZ = %d\n", BUFSIZ);

	return 0;
}
