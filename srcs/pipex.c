/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:25 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/01 16:06:36 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av,char **env)
{
    t_pipe pipex;
    
    if (ac != 5)
        return (send_error("Wrong arg\n"),0);   
    if (!access_or_error(&pipex))
        return (0);
    if (pipe(pipex.pipe_fd) == -1)
		return(send_error("error pipe"),0);
    
    return (1);
}



 /*if (pipe(fd) == -1)
    {
        perror("pipe");
        return (0);
    }
    child = fork();
    if (child == -1)
    {
        perror("fork");
        return(0);
    }
    if (child == 0)
    {
		if (dup2(fd[1],STDIN_FILENO) == -1)
        {
            perror("dup2");
            return (0);
        }
        close(fd[0]);
        close(fd[1]);
        //if (execve(cmd1) == -1)
        {
            perror("execve error");
            return (0); 
        }
    }
    else
    {
		if (dup2(fd[0],STDOUT_FILENO) == -1)
        {
            perror("dup2");
            return (0);
        }
        close(fd[0]);
        close(fd[1]);
        //if (execve(cmd1) == -1)
        {
            perror("execve error");
            return (0); 
        }
        if (wait(&status) == -1)
        {
            perror("wait");
            return (0);
        }
    }
    if (close(fd[0]) == -1) 
    {
        perror("close");
        return(0);
    }
    if (close(fd[1]) == -1) 
    {
        perror("close");
        return (0);
    }
    if (unlink(fd) == -1)
    {
        perror("unlink");
        return (0);
    }*/