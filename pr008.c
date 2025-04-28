//Программа записи информации из процесса в файл
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;
	size_t size;
	char string[] = "Chto to drygoe 3.008.2.24\n";
	if((fd = open("myfile", O_WRONLY | O_CREAT, 0666))<0) {
		printf("Ошибка при открытии файла");
		exit(-1);
	}	
	size = write(fd,string,26);
	if(size !=26) {
		printf("Не удалось записать всю строку");
		exit(-1);
	}	
	printf("В файл с дескриптором %d записано %ld байт\n", fd, size);
	if (close(fd)<0) {
		printf("Не удается закрыть файл с дескриптором %d\n", fd);
		exit(-1);
	}	
	return 0;	
}	
