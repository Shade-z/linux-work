#include "myhead.h"
bool viewMod_1(const int *fd){
	bool err = false;
	int accmode, val;
	if((*fd) < 0){
		printf("请先创建文件！\n");
	}else{
		if((val = fcntl((*fd), F_GETFL)) < 0){
			printf("ffcntl error for fd %d\n", (*fd));
			err = true;
		}else{
			printf("文件权限为:");
			accmode = val & O_ACCMODE;
			if(accmode == O_RDONLY) printf("read only");
			else if(accmode == O_WRONLY) printf("write only");
			else if(accmode == O_RDWR) printf("read write");
			else printf("unknown access mode");
			if(val & O_APPEND)  printf(",append");
			if(val & O_NONBLOCK)  printf(",nonblocking");
			#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
				if(val & O_SYNC)  printf(", synchronous writes");
			#endif
			putchar('\n');
		}
	}
	return err;
/*
struct stat buf;
	if(argc == 1 )
	{
		printf("Using %s filename\n",argv[0]);
		return 0;
	}
	if(lstat(argv[1],&buf) == -1)
	{
		printf("stat error:%s\n",strerror(errno));
		return -1;
	}
	printf("st_mode :%o\n",buf.st_mode);
 
	int n;
	for(n=8;n>=0;n--)
	{
		if(buf.st_mode&(1<<n))
		{
			switch(n%3)
			{
			case 2:
				printf("r");
				break;
			case 1:
				printf("w");
				break;
			case 0:
				printf("x");
					break;
			default:
				break;
 
			}
		}
		else
		{
			printf("-");
		}
	}
	printf("\n");
————————————————
版权声明：本文为CSDN博主「MrBugYang」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/linux_ly/article/details/6681307
*/
}
