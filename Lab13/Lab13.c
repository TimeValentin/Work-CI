#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/* 
	Написать программу, обрабатывающую получение сигналов 
	(SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM). 
	Также программа, может возбуждать эти сигна-лы 
	по указанию пользователя. 
	В качестве обработчика должно быть реализовано 
	логи-рование (вывод на консоль).	
*/

volatile sig_atomic_t flag = 0;

void function(int sig) 
{
    flag = sig;
    const char *names[] = 
	{
        [SIGABRT] = "SIGABRT",
        [SIGFPE]  = "SIGFPE",
        [SIGILL]  = "SIGILL",
        [SIGINT]  = "SIGINT",
        [SIGSEGV] = "SIGSEGV",
        [SIGTERM] = "SIGTERM"
    };
    printf("Signal %s received\n", names[sig]);
}

int main(int argc, char *argv[]) 
{
	int sigs[] = {SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM};
    const char *signames[] = {"SIGABRT", "SIGFPE", "SIGILL", "SIGINT", "SIGSEGV", "SIGTERM"};
    int n = sizeof(sigs) / sizeof(sigs[0]);
    int input;
	int i;
    for (i = 0; i < n; i++)
	{
        signal(sigs[i], function);
	}

    while (1) 
	{
        printf("\nRaise signal:\n");
        for (i = 0; i < n; i++)
        printf("%d. %s / %d\n", i + 1, signames[i], sigs[i]);
		printf("enter: ");
        scanf("%d", &input);
        
        if (input >= 1 && input <= n) 
		{
            flag = 0;
            raise(sigs[input - 1]);
        }
    }
    return 0;
}
