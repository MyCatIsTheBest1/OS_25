//Программа-отправитель информации в fifo
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
	
	printf("Процесс отправитель начинает запись в fifo\n");
	if((fd = open(name, O_WRONLY)) < 0) {
		printf("Не удалось открыть fifo на запись\n");
		exit(-1);
	}
	size = write(fd, "Текстовая строка для fifo", BYTES1);
	if(size != BYTES1) {
		printf("Не удалось записать всю строку в fifo\n");
		exit(-1);
	}
	if(close(fd) < 0) {
		printf("Не удалось закрыть fifo\n");
		exit(-1);
	}
	printf("Отправитель записал строку в fifo и завершает работу\n");
	return 0;
}

