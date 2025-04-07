//Программа, порождающая дочерний процесс (часть 1)
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	pid_t procid, pprocid;
	int a=0, b;
	procid = getpid();
	pprocid = getppid();
	printf("Ид. текущ. процесса: %d\nИд. род. процесса: %d\n", procid, pprocid);
	printf("Начальное значение а: %d\n", a);
	b = fork();
	a = a+1;
	procid = getpid();
	pprocid = getppid();
	printf("Ид. текущ. процесса: %d\nИд. род. процесса: %d\nНовое значение а: %d\n", procid, pprocid, a);
	return 0;
}	
