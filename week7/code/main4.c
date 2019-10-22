#include<unistd.h>
#include<iostream>
#include<fcntl.h>
#include<string>
#include<cstring>
#include<sys/types.h>
#include<sys/stat.h>
using namespace std;
int main(){
	int fd;
	FILE *file;
	char *s = "hello world\n";
	if((fd=open("test.txt",O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR)==-1)){
		cout<<"ERROR OPEN FILE1"<<endl;
		return -1;
	}
	if((file=fopen("test2.txt","w+"))==NULL){
		cout<<"ERROR OPEN FILE2"<<endl;
		return -1;
	}
	sleep(15);
	if(write(fd,s,strlen(s))<strlen(s)){
		cout<<"WRITE ERROR1"<<endl;
		return -1;
	}
	if(fwrite(s,sizeof(char),strlen(s),file)<strlen(s)){
		cout<<"WRITE ERROR2"<<endl;
		return -1;
	}
	cout<<"After write"<<endl;
	sleep(15);
	cout<<"After sleep"<<endl;
	close(fd);
	return 0;
}
