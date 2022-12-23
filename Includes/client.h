/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:26:55 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/23 14:37:19 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "ft_printf.h"
# include <sys/types.h>
# include <signal.h>

//client_main.c
int		ft_extract_pid(char *str, int *pid);
int		ft_send_message(char *str, int pid);
int		ft_send_char(char c, int pid);
void	ft_call_kill(int pid, int user);

#endif
