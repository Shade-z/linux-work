#include "myhead.h"
bool writeTofile_1(const int *fd){
	bool err = false;
	char content[arrayLength];
	int re = 0;
	if((*fd) < 0){
		printf("请先创建新文件\n");
	}else {
		if(lseek((*fd),0,SEEK_END) == -1) {
			printf("移动文件指针失败");
			err = true;
		}else {
			printf("请输入要添加的内容(不含空格且长度不超过20的字符串):");
			re = scanf("%20s", content);
			if(re == 1){
				printf("读取内容成功!正在写入文件!\n");
				re = write((*fd), content, strlen(content));
				if(re < 0){
					printf("写入失败!\n");
					err = true;
				}else{
					printf("写入成功!\n");
				}
			}else{
				printf("读取内容失败!");
				err = true;
			}
		}
	}
	return err;
}
