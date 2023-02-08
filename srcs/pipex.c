/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:25 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/08 19:02:49 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av,char **env)
{
    t_pipe pipex;
    
    int i = 0;
    if (ac != 5)
        return (send_error("Wrong arg\n"),0);
    pipex_init(ac,av,&pipex);
    if (pipe(pipex.pipe_fd) < 0)
		return(send_error("error pipe"),0);
    pipex.path = path_env(env);
    pipex.cmd_path = ft_split(pipex.path, ':');
    pipex.child = fork();
    if (pipex.child == 0)
        child(pipex,av,env);
    pipex.parent = fork();
    if (pipex.parent == 0)
        parent(&pipex, av, env);
    close_pipe(&pipex);
    waitpid(pipex.child, NULL, 0);
    waitpid(pipex.parent, NULL, 0);
    free_parent(&pipex);
    return (1);
}