/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:18:23 by wmessmer          #+#    #+#             */
/*   Updated: 2023/02/17 18:01:35 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	bonus_init(char **av, int ac,t_pipe_b *pipex)
{
	if (pipex->here == 0)
	{
		pipex->infile = open(av[1],O_RDONLY);
		if (pipex->infile < 0)
			bonus_error(0);
		pipex->outfile = open(av[ac - 1], O_CREAT | O_RDWR |O_TRUNC, 0000644);
		if (pipex->outfile < 0)
			bonus_error(1);
	}
	else
	{
		pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0000644);
		if (pipex->outfile < 0)
			bonus_error(1);
		here_doc(av[2],pipex);
	}
	pipex->cmd_nb = ac - 3 - pipex->here;
	
}
void bonus_error(int a)
{
	if (a == 0)
		send_error("Can't open infile");
	if (a == 1)
		send_error("Can't open outfile");
	if (a == 2)
		send_error("Pipe error");
	exit(1);
}