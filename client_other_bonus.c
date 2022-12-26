/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_other_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:27:41 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/26 16:29:35 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_quit_wrong_pid(void)
{
	ft_putstr_fd("Wrong PID\n", 2);
	exit (0);
}

void	ft_quit_message(char *str)
{
	ft_putstr_fd(str, 2);
	exit (0);
}
