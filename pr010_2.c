//Программа для чтения информации из fifo
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BYTES1 44


int main () {
	int fd;
	size_t size;
	char resstring[BYTES1];
	char name[]="file.fifo";
	/*
	if(mknod(name, S_IFIFO | 0664, 0) < 0) {
		printf("Не удалось создать файл fifo\n");
		exit(-1);
	}
	*/
	
	printf("Процесс-приемник готов к чтению информации из fifo\n");
	if((fd = open(name, O_RDONLY)) < 0) {
		printf("Не удалось открыть fifo на чтение\n");
		exit(-1);
	}
	size = read(fd, resstring, BYTES1);
	if(size < 0) {
		printf("Не удалось прочитать строку из fifo\n");
		exit(-1);
	}		
	printf("Содержимое прочитанной строки: %s\n", resstring);
	if(close(fd) < 0) {
		printf("Не удалось закрыть fifo\n");
		exit(-1);
	}
	printf("Процесс-приемник завершает работу\n");
	return 0;
}
