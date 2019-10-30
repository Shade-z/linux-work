#include "myhead.h"
bool createNew_1(int *fd, char filename[]){
	bool err = false;
	int reValue = 0;
	char temp[arrayLength];
	if((*fd) > 0) close((*fd));//如果之前已创建了新文件,则关闭之前的那个文件
	printf("请输入要创建的文件名(不含空格):");
	reValue = scanf("%20s", temp);
	if(reValue!=1){
		printf("输入文件名格式错误:reValue=%d,input=%s\n", reValue, temp);
	}else{
		strcpy(filename, temp);
		//printf("2--temp=%s,filename=%s\n",temp,filename);
		if(((*fd) = open(filename, default_flags, default_mode)) < 0){
			printf("创建新文件失败\n");
			err = true;
		}
		printf("filename=%s,fd=%d\n", filename, *fd);
	}
	return err;
}
