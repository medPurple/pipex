/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:08 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/31 22:27:20 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../42-libft/include/libft.h"


/*mandatory access*/
int access_or_error(char *f1, char *f2);
int verif_access(char *file);

# endif