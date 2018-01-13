#include <stdio.h>
#include <unistd.h>
int main(){
	printf ("Main before fork()\n");
	int pid = fork();
	if (pid == 0) {
		printf("I am child after fork(), launching ps -ef\n");
		char *args[]= { "/bin/ps", "-ef" , NULL};
		execvp("/bin/ps", args);
		printf("Finished launching ps -ef\n");
		}
	else 
		{
		char *args[]= { "free", "-h", NULL};
		execvp("free", args);
		printf("Finished launching\n");
		}
	return 0;
}

