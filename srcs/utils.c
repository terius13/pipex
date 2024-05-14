/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:55:01 by ting              #+#    #+#             */
/*   Updated: 2024/05/14 21:10:52 by ting             ###   ########.fr       */
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
    
}