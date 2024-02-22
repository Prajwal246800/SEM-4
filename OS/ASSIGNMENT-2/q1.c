// Using Pipes, Reverse a String 
//  * One Process Takes inthe string as input and writes it to a pipe
//  *The Other Process Reads From the Pipe and Reverse The String  

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<stdlib.h>

#define MAX_STRING_LENGTH 100

int main()
{
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0)
    {
        close(fd[0]);
        char input_string[MAX_STRING_LENGTH];
        printf("Enter a string (max %d characters): ", MAX_STRING_LENGTH);
        fgets(input_string, MAX_STRING_LENGTH, stdin);
        input_string[strcspn(input_string, "\n")] = '\0';
        if (write(fd[1], input_string, strlen(input_string) + 1) == -1)
        {
            perror("write");
            exit(1);
        }
        close(fd[1]);
        wait(NULL);
        printf("Parent process waiting for child...\n");
    }

    else
    {
        close(fd[1]);
        char reversed_string[MAX_STRING_LENGTH];
        int i, len;
        if (read(fd[0], reversed_string, MAX_STRING_LENGTH) == -1)
        {
            perror("read");
            exit(1);
        }
        len = strlen(reversed_string);
        for (i = 0; i < len / 2; i++)
        {
            char temp = reversed_string[i];
            reversed_string[i] = reversed_string[len - i - 1];
            reversed_string[len - i - 1] = temp;
        }
        reversed_string[len] = '\0';
        printf("Reversed string: %s\n", reversed_string);
        close(fd[0]);
    }
    return 0;
}