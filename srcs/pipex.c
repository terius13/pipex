/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:54:51 by ting              #+#    #+#             */
/*   Updated: 2024/05/12 18:05:39 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **env)
{   
    int fd[2];
    int pid;
    
    if (argc == 5)
    {
        if (pipe(fd) == -1)
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