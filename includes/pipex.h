/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:52:53 by ting              #+#    #+#             */
/*   Updated: 2024/05/15 21:35:14 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

//pipex.c
void    child_process(int *end, char **argv, char **env);
void    parent_process(int *end, char **argv, char **env);

//utils.c
void	error(void);
void    ft_free(char **str);
char    *find_path(char *cmd, char **env);

#endif