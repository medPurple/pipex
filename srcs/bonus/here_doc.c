/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:01:59 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/21 09:51:59 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int here_or_not(char *av,t_pipe_b *pipex)
{
	if(av && (ft_strcmp(av,"here_doc")) == 0)
	{
		pipex->here = 1;
		return (6);
	}
	else
	{
		pipex->here = 0;
		return (5);
	}
}

void here_doc(char *limiter, t_pipe_b *pipex)
{
	char *line;

	if (pipe(pipex->pipe_fd_b) < 0)
		bonus_error(2);
	//pipex->child = fork();
	//if (pipex->child == 0)
	//{
		close(pipex->pipe_fd_b[0]);
		ft_printf("BEFORE GNL\n");
		while (1)
		{
			line = get_next_line(0);
			ft_printf(" Line = %s\n Limiter = %s \n Len limiter = %i",line,limiter,ft_strlen(limiter));
			if (ft_strncmp(line,limiter,ft_strlen(limiter)) == 0)
			{
				ft_printf("exit");
				exit(EXIT_SUCCESS);
			}
			free(line);
			//write(pipex->pipe_fd_b[1],line, ft_strlen(line));
		}
	//}
	/*else
	{
		close(pipex->pipe_fd_b[1]);
		dup2(pipex->pipe_fd_b[0],STDIN_FILENO);
		wait(NULL);
	}*/
}