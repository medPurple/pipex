/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:24:21 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/08 19:01:22 by wmessmer         ###   ########.fr       */
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
	int		status;
    pid_t child;
	pid_t parent;
}		t_pipe;


int verif_access_f1(t_pipe *pipex);
int verif_access_f2(t_pipe *pipex);
void access_or_error(t_pipe *pipex);
void pipex_init(int ac,char **av, t_pipe *pipex);
char *path_env(char **env);
char *get_cmd(char **paths, char *cmd);
void child(t_pipe pipex, char **av, char **env);
void parent(t_pipe *pipex, char **av, char **env);
void	free_child(t_pipe *pipex);
void	free_parent(t_pipe *pipex);
void close_pipe(t_pipe *pipex);

#endif