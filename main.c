#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#define MAXLINE 4096
int main()
{
    char    buf[MAXLINE];
    pid_t   pid;
    int status;
    //zmiana

    printf("%% "); //znak zachęty
    while(fgets(buf,MAXLINE,stdin)!=NULL){
        buf[strlen(buf) - 1] = 0; // zastępujemy znak nowego wiersza pustym znakiem
    if((pid=fork()) < 0)
            printf("fork error");
    else if(pid == 0)
        {//proces potomnY
            execlp(buf,buf,(char*)0);
            printf("Nie mozna uruchomic: %s",buf);
            printf("\n");
            exit(127);
        }
    //proces macierzysty
    if( (pid=waitpid(pid, &status, 0) ) < 0)
        printf("waitpid error");
        printf("%% ");
    }

    return 0;
}
