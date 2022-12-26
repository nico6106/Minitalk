/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:26:55 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/26 15:51:15 by nlesage          ###   ########.fr       */
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
void	ft_handle_signal(int n);

//client_other.c
void	ft_quit_wrong_pid(void);

#endif
