#include "myhead.h"
bool changeMod_1(const char filename[]){
	bool err = false;
	int mode;
    /*int mode_u;//所有者权限
    int mode_g;//所属组权限
    int mode_o;//其他人权限*/
	if(filename == NULL){
		printf("请先创建文件！\n");
	}else{
		printf("请输入要修改的权限,格式为八进制:");
		scanf("%o", &mode);
		/*if(mode>777||mode<0){//验证要设置的权限是否合法
		    printf("输入的权限不合法!\n"); 
		    err = true;
		}
		mode_u=mode/100; 
		mode_g=mode/10%10;
		mode_o=mode%10;
		mode=mode_u*8*8+mode_g*8+mode_o;//八进制转换
		*/
		if(chmod(filename, mode)==-1){//调用chmod函数进行权限修改
			printf("修改权限失败！\n%s\n", filename);
		   //err = true;
		}else{
			printf("修改权限成功！\n");
		}
	}
	return err;
}
