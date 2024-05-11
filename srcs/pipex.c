/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:54:51 by ting              #+#    #+#             */
/*   Updated: 2024/05/11 20:49:46 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **env)
{   
    int fd[2];
    
    if (argc == 5)
    {
        if (pipe(fd) == -1)
            perror("pipe");
        else if 
    }
    return (0);
}