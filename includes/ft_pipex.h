/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:42:57 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/20 00:59:56 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H

# define FT_PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

void	ft_pipex(char **args, int fd_in, int fd_out);
void	error_exit(void);
void	put_problem_ident(char *problem_key);
void	ft_free_char_mtrx(char **matrix);
void	wait_for_all(void);

#endif