/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:06:46 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/03 17:55:20 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void pipex_init(char **av,char **env, t_pipe *pipex)
{
    pipex->file_in = av[1];
    pipex->file_out = av[4];
    pipex->path = path_env(env);
    pipex->cmd_path = ft_split(pipex->path,':');
    pipex->child = fork();
    pipex->parent = fork();
    
}

char *path_env(char **env)
{
	while (ft_strncmp("PATH",*env,4) != 0)
		env++;
	return (*env);
}

char *get_cmd(t_pipe *pipex)
{
	char *cmd;
    char *cmd_path;
    
    cmd_path = *pipex->cmd_path;

    while(cmd_path)
    {
        cmd = ft_strjoin(ft_strjoin(cmd_path, "/"),cmd);
        if (access(cmd,0) == 0)
            return (cmd);
        free (cmd);
        cmd++;
    }
    return (NULL);
}