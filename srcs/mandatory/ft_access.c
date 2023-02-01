/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:20:21 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/01 16:01:26 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int verif_access(char *file,int fd)
{
    if (access(file,F_OK) == -1)
    {
        ft_printf("File %s doesn't exit, creating one...\n",file);
        fd = open(file,O_RDONLY | O_CREAT, 0666);
        if (!fd)
        {
            perror("open");
            return (0);
        }
    }
    return (1);
}

int access_or_error(t_pipe *pipex)
{
    if (!verif_access(pipex->file_in,pipex->infile))
    {
        send_error("Error with the first file");
        return (0);
    }
    if (!verif_access(pipex->file_out,pipex->outfile))
    {
        send_error("Error with second file");
        return (0);
    }
    return (1);
}