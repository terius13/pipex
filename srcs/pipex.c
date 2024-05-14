/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:54:51 by ting              #+#    #+#             */
/*   Updated: 2024/05/14 20:44:07 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//$> ./pipex infile "ls -l" "wc -l" outfile
//child: infile "ls -l"
//parent: "wc -l" outfile

void    child_process(int *end, char **argv, char **env)
{
    int infile;
    
    infile = open(argv[1], O_RDONLY, 0777);
    dup2(infile, STDIN_FILENO); //redirect stdin to infile, stdin now reads from infile
    close(infile); //not needed anymore
    dup2(end[1], STDOUT_FILENO); //redirect stdout to pipe's end[1]. Instead of output to screen, it now outputs to pipe's end[1]
    close(end[1]); //not needed anymore, now in stdout
    close(end[0]); //close the other end of the pipe
    //execve();
}

void    parent_process(int *end, char **argv, char **env)
{
    int outfile;

    outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    dup2(end[0], STDIN_FILENO);
    close(end[0]); //not needed anymore
    dup2(outfile, STDOUT_FILENO);
    close(outfile); //not needed anymore
    close(end[1]); //close the other end of the pipe
    //execve();
}

int main(int argc, char **argv, char **env)
{   
    int end[2];
    int pid;
    
    if (argc == 5)
    {
        if (pipe(end) == -1)
            perror("pipe");
        pid = fork();
        if (pid == -1)
            perror("fork");
        else if (pid == 0)
        {
            //enter child process execution
            printf("The child pid is: %d\n", getpid());
        }
        else if (pid > 0)
        {
            waitpid(pid, NULL, 0);
            //enter parent process execution
            printf("The parent pid id: %d, the child pid is: %d\n", getpid(), pid);
        }
    }
    return (0);
}