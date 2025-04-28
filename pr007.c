//Изменение пользовательского контекста процесса во время выполнения программы
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
	printf("Программа начала работу ...\n");
	pid_t pid, ppid;
	int result;
	pid = getpid();
	ppid = getppid();
	printf("ID процесса %d\n", pid);
	printf("ID род. процесса %d\n", ppid);
	result = fork();
	if (result > 0) {
		printf("Родительский процесс ...\n");
		printf("ID процесса %d, ID процесса ребенка %d\n", pid, result);
        	printf("ID род. процесса %d\n", ppid);
		printf("Родитель закончил работу\n");
	}
	else if (result == 0) {
		printf("Дочерний процесс ...\n");
		(void) execle("./pr003.out", "./pr003.out", 0, envp); 
		printf("Ошибка при выполнении системного вызова exec\n");
		exit(-1);
	}
	else {
		printf("Ошибка при выполнении системного вызова Fork\n");
		exit(-1);
	}	
	return 0;
}	
