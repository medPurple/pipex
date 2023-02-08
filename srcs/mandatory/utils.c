/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:06:46 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/08 19:03:16 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void pipex_init(int ac,char **av, t_pipe *pipex)
{
    pipex->file_in = av[1];
    pipex->file_out = av[ac - 1];
	pipex->fd_infile = open(pipex->file_in,O_RDONLY);
    pipex->fd_outfile = open(pipex->file_out, O_TRUNC | O_CREAT | O_RDWR, 0000644);
}

char *path_env(char **env)
{
	while (ft_strncmp("PATH",*env,4))
		env++;
	return (*env+5);
}

char *get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
    return (NULL);
}

void close_pipe(t_pipe *pipex)
{
	close(pipex->pipe_fd[0]);
    close(pipex->pipe_fd[1]); 
}