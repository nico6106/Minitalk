/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:28:04 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/26 16:48:15 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_BONUS_H
# define SERVEUR_BONUS_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

typedef struct s_var
{
	unsigned int	i;
	unsigned int	position;
	unsigned int	bit;
}	t_var;

//serveur_main.c
void	ft_handle(int n, siginfo_t *info, void *context);
void	ft_print_message(char *str, int pid);

#endif
