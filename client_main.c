/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:29:08 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/22 15:03:06 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Error with the arguments entered\n", 2);
		return (0);
	}
	if (ft_extract_pid(argv[1], &pid) == 0)
	{
		ft_putstr_fd("Error with the PID entered\n", 2);
		return (1);
	}
	ft_printf("pid entered=%d\n", pid);
	ft_send_message(argv[2], pid);
	return (0);
}

int	ft_extract_pid(char *str, int *pid)
{
	if (ft_str_is_number(str) == 0)
		return (0);
	*pid = ft_atoi(str);
	return (1);
}

int	ft_send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(str[i], pid);
		i++;
	}
	ft_send_char(0, pid);
	return (0);
}

int	ft_send_char(char c, int pid)
{
	int	i;
	unsigned char	tmp;

	i = 1;
	while (i <= 8)
	{
		tmp = (c << (8 - i) & 128) >> (7); 
		if (tmp == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		//ft_printf("ft_send_char: tmp=%d\n", tmp);
		usleep(500);
		i++;
	}
	return (0);
}
