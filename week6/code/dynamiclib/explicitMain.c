#include<dlfcn.h>
#include<stdlib.h>
#include"mylib.h"
void testErr(char *pszErr){
	pszErr = dlerror();
	if(pszErr != NULL){
		printf("%s\n", pszErr);
		exit(1);
	}
}
int main(){
	int Num = 20, array[Num];
	void (*pvoid)(int *, int);
	int (*pint)(int *, int);
	void *pdlHandle = dlopen("./libdytest.so", RTLD_LAZY);
	char *pszErr = NULL;
	if(pdlHandle == NULL){
		printf("Failed load library\n");
		exit(1);
	}
	testErr(pszErr);

	pvoid = dlsym(pdlHandle, "init");
	testErr(pszErr);
	pvoid(array, Num);
	
	pvoid = dlsym(pdlHandle, "show");
	testErr(pszErr);
	pvoid(array, Num);
	
	pint = dlsym(pdlHandle, "max");
	testErr(pszErr);
	printf("\nmax=%d\n", pint(array, Num));
	
	pint = dlsym(pdlHandle, "min");
	testErr(pszErr);
	printf("min=%d\n", pint(array, Num));

	dlclose(pdlHandle);
	return 0;
}
