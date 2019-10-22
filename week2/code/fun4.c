#include"uhead.h"
void writeArrayTo(const char* pathName, int *array, int length){
	if(pathName!=NULL && strcmp(pathName,"")){
		FILE* fp;
		int i=0;
		if((fp = fopen(pathName, "w+")) == NULL){
			return NULL;
		}
		for(;i<length;i++){
			fprintf(fp, "%d\n", array[i]);
		}
		fclose(fp);
	}
}
