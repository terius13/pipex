/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:55:01 by ting              #+#    #+#             */
/*   Updated: 2024/05/15 21:38:49 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void    ft_free(char **str)
{
    int  i;

    i = 0;
    while (str[i])
    {
        free (str[i]);
        i++;
    }
}

char	*find_path(char *cmd, char **env)
{
	char	*path_in_env;
	char	**path_segments;
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path_in_env = NULL;
	while (path_in_env == 0 && env[i])
		path_in_env = ft_strnstr(env[i++], "PATH", 4);
	path_in_env += 5;
	path_segments = ft_split(path_in_env, ':');
	while (path_segments[j])
	{
		path = ft_strjoin(path_segments[j], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) != 0)
			free(path);
		else
			return (ft_free(path_segments), path);
		j++;
	}
	return (NULL);
}
