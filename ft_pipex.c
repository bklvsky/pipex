/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:41:00 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/22 19:22:50 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_pipex.h"

char	*find_path(char **paths_tmp, char **cmd_args)
{
	int		i;
	char	*tmp;
	char	*new_path;

	i = -1;
	while (paths_tmp[++i])
	{
		tmp = ft_strjoin(paths_tmp[i], "/");
		if (!tmp)
			error_exit();
		new_path = ft_strjoin(tmp, cmd_args[0]);
		free(tmp);
		if (!new_path)
			error_exit();
		if (access(new_path, F_OK & X_OK) == 0)
			return (new_path);
		free(new_path);
	}
	return (NULL);
}

void	find_exec(char **cmd_args)
{
	char	**paths_tmp;
	char	*exec_path;
	int		i;

	i = -1;
	while (__environ[++i])
	{
		if (ft_strncmp(__environ[i], "PATH", 4) == 0)
			break ;
	}
	paths_tmp = ft_split(__environ[i] + 5, ':');
	if (!paths_tmp)
		error_exit();
	exec_path = find_path(paths_tmp, cmd_args);
	ft_free_char_mtrx(paths_tmp);
	if (!exec_path)
	{
		put_problem_ident(cmd_args[0]);
		ft_free_char_mtrx(cmd_args);
		error_exit();
	}
	execve(exec_path, cmd_args, __environ);
}

void	pipe_in(char *cmd1, int *pipefd, int fd_in)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd1, ' ');
	if (!cmd_args)
		error_exit();
	close(pipefd[0]);
	if (dup2(fd_in, 0) < 0 || dup2(pipefd[1], 1) < 0)
		error_exit();
	if (cmd1[0] != '/')
		find_exec(cmd_args);
	else
		execve(cmd_args[0], cmd_args, __environ);
	put_problem_ident(cmd_args[0]);
	ft_free_char_mtrx(cmd_args);
	close(fd_in);
	close(pipefd[1]);
	error_exit();
}

void	pipe_out(char *cmd2, int *pipefd, int fd_out)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd2, ' ');
	if (!cmd_args)
		error_exit();
	close(pipefd[1]);
	if (dup2(fd_out, 1) < 0 || dup2(pipefd[0], 0) < 0)
		error_exit();
	if (cmd2[0] != '/')
		find_exec(cmd_args);
	else
		execve(cmd_args[0], cmd_args, __environ);
	put_problem_ident(cmd_args[0]);
	ft_free_char_mtrx(cmd_args);
	close(fd_out);
	close(pipefd[0]);
	error_exit();
}

void	ft_pipex(char **args, int fd_in, int fd_out)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		error_exit();
	pid = fork();
	if (pid < 0)
		error_exit();
	if (pid == 0)
		pipe_in(args[2], pipefd, fd_in);
	else
	{
		close(pipefd[1]);
		pid = fork();
		if (pid < 0)
			error_exit();
		else if (pid == 0)
			pipe_out(args[3], pipefd, fd_out);
		else
			wait_for_all();
	}
}
