/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:26:44 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/27 11:44:34 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/serveur.h"

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_handle;
	sigaddset(&sa.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error with signal\n", 2);
	(void) argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error, there should not be any arguments\n", 2);
		return (1);
	}
	pid = getpid();
	ft_printf("PID=%d\n", pid);
	while (argc == 1)
		sleep(1);
}

void	ft_print_message(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_handle(int n, siginfo_t *info, void *context)
{
	static t_var	var;
	static char		str[1000000];
	int				j;

	(void) context;
	if (n == SIGUSR1)
		var.i = var.i | (0x01 << var.bit);
	var.bit++;
	if ((var.bit == 8 && var.i == 0) || var.position == (1000000 - 1))
	{
		ft_print_message(str);
		j = -1;
		while (++j <= var.position)
			str[j] = 0;
		var.position = 0;
		var.bit = 0;
		var.i = 0;
	}
	else if (var.bit == 8)
	{
		str[var.position++] = var.i;
		var.bit = 0;
		var.i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
