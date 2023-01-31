/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:19 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/31 22:34:02 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av,char **env)
{
    char *file_in;
    char *file_out;
    int fd[2];
    pid_t child;
    if (ac != 5)
        return (send_error("Wrong arg\n"),0);
    file_in = av[1];
    file_out = av[4];
    if (!access_or_error(file_in, file_out))
        return (0);
    if (pipe(fd) == -1)
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
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
    }
        
    return (1);
}