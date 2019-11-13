#include "head.h"
int g=999;
int main()
{
   pid_t pid;
   int i=888;
   static int k=777;
   pid=vfork();
   int s;
   if(pid<0){
        perror("fork failed!\n");
        exit(-1);
   }
   else if(pid==0){
        printf("%d:child is runing!\n",getpid());
        printf("child :&g=%16p\n&i=%16p\n&k=%16p\n",&g,&i,&k);
        execl("./test","test",NULL);//这句执行后会替换掉子进程后面的代码，因此最后返回值就不是12
        printf("child after execl!\n");
        _exit(12);
 
   }else{
        wait(&s);
        printf("parent is runing!exit code =%d\n",WEXITSTATUS(s));
        printf("parent will finish!\n");
        return 0; 
     }
}
