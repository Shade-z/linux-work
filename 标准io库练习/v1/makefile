main:main.o menu_1.o createNew_1.o writeTofile_1.o readFromfile_1.o changeMod_1.o viewMod_1.o
	gcc main.o menu_1.o createNew_1.o writeTofile_1.o readFromfile_1.o changeMod_1.o viewMod_1.o -o main -I./
main.o:main.c
	gcc main.c -c
menu_1.o:menu_1.c
	gcc menu_1.c -c
createNew_1.o:createNew_1.c
	gcc createNew_1.c -c
writeTofile_1.o:writeTofile_1.c
	gcc writeTofile_1.c -c
readFromfile_1.o:readFromfile_1.c
	gcc readFromfile_1.c -c
changeMod_1.o:changeMod_1.c
	gcc changeMod_1.c -c
viewMod_1.o:
	gcc viewMod_1.c -c
clean:
	rm -f *.o
