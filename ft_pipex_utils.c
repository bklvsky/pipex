/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:56:01 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/20 01:06:39 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_pipex.h"

void	ft_free_char_mtrx(char **matrix)
{
	int		i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	put_problem_ident(char *problem_key)
{
	ft_putstr_fd(problem_key, 2);
	write(2, ": ", 2);
}

void	error_exit(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	wait_for_all(void)
{
	int		temp;

	temp = 1;
	while (temp > 0)
	{
		temp = wait(NULL);
	}
}
