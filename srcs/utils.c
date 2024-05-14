/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:55:01 by ting              #+#    #+#             */
/*   Updated: 2024/05/14 21:31:16 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char    *find_path(char *cmd, char **env)
{
    char    *path_in_env;
    int i;

    i = 0;
    path_in_env = ft_strnstr();
    while ((path_in_env = ft_strnstr(env[i], "PATH", 4)) == 0)
        i++;

    //add the command behind the path to try it with access; etc bin/ls to try for ls
    
}