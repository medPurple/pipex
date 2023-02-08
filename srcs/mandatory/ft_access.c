/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:20:21 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/08 12:09:52 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int verif_access_f1(t_pipe *pipex)
{
    if (access(pipex->file_in,F_OK) == -1)
    {
        pipex->fd_infile = open(pipex->file_in,O_RDONLY);
        if (pipex->fd_infile < 0)
        {
            perror("open");
            return (0);
        }
    }
    return (1);
}

int verif_access_f2(t_pipe *pipex)
{
    if (access(pipex->file_out,F_OK) == -1)
    {
        pipex->fd_outfile = open(pipex->file_out,O_TRUNC | O_CREAT | O_RDWR, 0000644);
        if (pipex->fd_outfile < 0)
        {
            perror("open");
            return (0);
        }
    }
    return (1);
}

void access_or_error(t_pipe *pipex)
{
    if (!verif_access_f1(pipex))
    {
        send_error("Error with the first file");
        exit(1);
    }
    if (!verif_access_f2(pipex))
    {
        send_error("Error with second file");
        exit (1);
    }
}