/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:20:21 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/31 22:26:39 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int verif_access(char *file)
{
    int fd;
    if (access(file,F_OK) == -1)
    {
        ft_printf("File %s doesn't exit, creating one...\n",file);
        fd = open(file,O_RDONLY | O_CREAT, 0666);
        if (!fd)
        {
            perror("open");
            return (0);
        }
        close(fd);
    }
    return (1);
}

int access_or_error(char *f1, char *f2)
{
    if (!verif_access(f1))
    {
        send_error("Error with the first file");
        return (0);
    }
    if (!verif_access(f2))
    {
        send_error("Error with second file");
        return (0);
    }
    return (1);
}