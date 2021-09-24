/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:23:58 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/24 17:23:49 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_pipex.h"

int	main(int argc, char **argv)
{
	int		fd_in;
	int		fd_out;

	if (argc != 5)
	{
		ft_putendl_fd("Usage:./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC);
	if (fd_in < 0)
	{
		put_problem_ident(argv[1]);
		error_exit();
	}
	else if (fd_out < 0)
	{
		put_problem_ident(argv[4]);
		error_exit();
	}
	ft_pipex(argv, fd_in, fd_out);
	return (0);
}
