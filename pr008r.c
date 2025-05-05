//Программа для чтения информации из файла в адресное пространтсво процесса
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;
	size_t size;
	char string[26];
	if((fd = open("myfile", O_RDONLY))<0) {
		printf("Ошибка при открытии файла на чтение");
		exit(-1);
	}	
	size = read(fd,string,26);
	if(size !=26) {
		printf("Не удалось прочитать всю строку");
		exit(-1);
	}
	else
		printf("Строка прочитана из файла \"myfile\"\n");	
	printf("Из файла с дескриптором %d прочитано %ld байт\n", fd, size);
	printf("Строка: %s\n", string);
	if (close(fd)<0) {
		printf("Не удается закрыть файл с дескриптором %d\n", fd);
		exit(-1);
	}	
	return 0;	
}	
