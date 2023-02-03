/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:25 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/03 17:58:27 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av,char **env)
{
    t_pipe pipex;
    
    if (ac != 5)
        return (send_error("Wrong arg\n"),0);
    pipex_init(av,env, &pipex);
    if (!access_or_error(&pipex))
        return (0);
    if (pipe(pipex.pipe_fd) == -1)
		return(send_error("error pipe"),0);
    pipex_init(av,env, &pipex);
    if (pipex.child == 0)
        child(&pipex,av,env);
    if (pipex.parent == 0)
        parent(&pipex,av,env);
    close(pipex.pipe_fd[0]);
    close(pipex.pipe_fd[1]);
    waitpid(pipex.child, NULL, 0);
    waitpid(pipex.parent, NULL, 0);
    free_parent(&pipex);
    return (1);
}