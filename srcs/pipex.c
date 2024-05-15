/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:54:51 by ting              #+#    #+#             */
/*   Updated: 2024/05/15 22:24:54 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//$> ./pipex infile "ls -l" "wc -l" outfile
// child: infile "ls -l"
// parent: "wc -l" outfile

void	child_process(int *end, char **argv, char **env)
{
	int		infile;
	char	*path;
	char	**cmd_split;

	infile = open(argv[1], O_RDONLY, 0777);
    if (infile == -1) {
        error();
    }
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	close(end[0]);
	printf("Child done executing: %d\n", getpid());
	cmd_split = ft_split(argv[2], ' ');
	path = find_path(cmd_split[0], env);
	if (path != NULL)
	{
		printf("Child cmd path: %s\n", path);
		if (execve(path, cmd_split, env) == -1)
        {
            ft_free(cmd_split);
			error();
        }
	}
	else
        error();
}

void	parent_process(int *end, char **argv, char **env)
{
	int		outfile;
	char	*path;
	char	**cmd_split;

	outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (outfile == -1) {
        error();
    }
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(end[1]);
	cmd_split = ft_split(argv[3], ' ');
	path = find_path(cmd_split[0], env);
	if (path != NULL)
	{
		if (execve(path, cmd_split, env) == -1)
			perror("Parent execve");
	}
	else
		perror("Parent path");
}

int	main(int argc, char **argv, char **env)
{
	int	end[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(end) == -1)
			perror("pipe");
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			child_process(end, argv, env);
		}
		else if (pid > 0)
		{
			waitpid(pid, NULL, 0);
			parent_process(end, argv, env);
		}
	}
	return (0);
}
