//Программа, порождающая дочерний процесс (часть 2).
//Процесс-родитель и процесс-ребенок должны выполнять разные действия
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	 pid_t procid, pprocid;
	 int a=0, b;
	 procid = getpid();
	 pprocid = getppid();
	 printf("id текущего процесса: %d\nid родительского процесса: %d\n", procid, pprocid);
	 printf("Начальное значение а: %d\n", a);
	 b = fork();
	 if (b<0) {
		//Во время выполнения fork() произошла ошибка. Выходим из программы с возвратом кода -1.
	 	printf("Ошибка при выполнении fork()\n");
		exit(-1); //выход из программы.
	 }
	else if (b==0) {
		printf("\n\nПоявился дочерний процесс\n");
		 a = a+1; //Проверяем изменение значения переменной а.
		procid = getpid();
		 pprocid = getppid();
		 printf("после вызова fork() в процессе ребенке%d\n", b);
		 printf("id текущего процесса:%d\nid текущего процесса:  %d\nНовое значение а: %d\n", procid, pprocid, a);
		}
	 else  {
	 printf("\n\nРодительский процесс после вызова fork() получил id ребенка: %d\n", b);
	 a = a+1111; //Проверяем изменение значение переменной а.
	 procid = getpid();
	 pprocid = getppid();
	 printf("Идентификатор процесса родителя:%d\n", procid);
	 printf("После вызова fork %d\n", pprocid);
	 printf("id текущего процесса:%d\nid родительского процесса: %d\nНовое значение а: %d\n ", procid, pprocid, a);
	 }

 return 0;

}
