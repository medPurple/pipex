/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:24:21 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/17 17:01:30 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "../libft/include/libft.h"

typedef struct s_pipe
{
	char	*file_in;
	char	*file_out;
	int		fd_infile;
	int		fd_outfile;
	int		pipe_fd[2];
	char	*path;
	char	*cmd;
	char	**cmd_path;
	char	**cmd_arg;
	pid_t	child;
	pid_t	parent;
}		t_pipe;

typedef struct s_pipe_b
{
	int here;
	int infile;
	int outfile;
	int cmd_nb;
	int pipe_fd_b[2];
	pid_t	child;	
}	t_pipe_b;

/* MANDATORY */

void	pipex_init(int ac, char **av, char **env, t_pipe *pipex);
char	*path_env(char **env);
char	*get_cmd(char **paths, char *cmd);
void	child(t_pipe *pipex, char **av, char **env);
void	parent(t_pipe *pipex, char **av, char **env);
void	free_child(t_pipe *pipex);
void	free_parent(t_pipe *pipex);
void	close_pipe(t_pipe *pipex);

/* BONUS */
void	bonus_init(char **av, int ac,t_pipe_b *pipex);
void bonus_error(int a);
void here_doc(char *limiter, t_pipe_b *pipex);
int here_or_not(char *av,t_pipe_b *pipex);

#endif
