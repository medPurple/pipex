/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:24:21 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/01 16:01:55 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define STDIN 0
# define STDOUT 1
# define STDERROR 2


# include "../libft/include/libft.h"
typedef struct s_pipe
{
	char	*file_in;
    char	*file_out;
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	char	*path;
	char	*cmd;
	char	*cmd_path;
	char	*cmd_arg;
	int		status;
    pid_t child;
}		t_pipe;


int verif_access(char *file, int fd);
int access_or_error(t_pipe *pipex);

#endif