#include "myhead.h"
bool readFromfile_1(const int *fd){
	bool err = false;
	char content[arrayLength];
	int re = 0;
	if((*fd) < 0){
		printf("请先创建新文件\n");
	}else {
		if(lseek((*fd),0,SEEK_SET) == -1) {
			printf("移动文件指针失败");
			err = true;
		}else {
			printf("正在读取文件内容!\n");
			re = read((*fd), content, arrayLength+1);
			if(re < 0){
				printf("读取内容失败!\n%s", content);
				err = true;
			}else{
				printf("读取内容成功!\n");
				while(re > 0){
					printf("%s", content);
					memset(content,'\0',arrayLength);
					re = read((*fd), content, arrayLength+1);
				}
				printf("\n");
			}
		}
	}
	return err;
}
