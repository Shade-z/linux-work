#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define arrayLength 20
#define default_flags (O_CREAT | O_RDWR | O_TRUNC | O_APPEND)
#define default_mode (0666)
typedef enum {
	false, true
} bool;
int menu();
bool createNew_1(int *, char []);
bool writeTofile_1(const int *);
bool readFromfile_1(const int *);
bool changeMod_1(const char []);
bool viewMod_1(const int*);
