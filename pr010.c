#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BYTES1 44


int main () {
	int fd, result;
	size_t size;
	char resstring[BYTES1];
	char name[]="file.fifo";
	/*
	if(mknod(name, S_IFIFO | 0664, 0) < 0) {
		printf("Не удалось создать файл fifo\n");
		exit(-1);
	}
	*/
	if ((result = fork()) < 0) {
		printf("Не удалось создать дочерний процесс\n");
		exit(-1);
	}
	else if (result > 0) {
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
		printf("Родитель записал строку в fifo и завершает работу\n");
	}
	else {
		if((fd = open(name, O_RDONLY)) < 0) {
			printf("е удалось открыть fifo на чтение\n");
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
	}
	return 0;
}

