/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:26:44 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/26 16:57:46 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur_bonus.h"

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
	{
		ft_putstr_fd("Error with signal\n", 2);
		exit (0);
	}
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

void	ft_print_message(char *str, int pid)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	kill(pid, SIGUSR2);
}

void	ft_handle(int n, siginfo_t *info, void *context)
{
	static t_var	var;
	static char		str[1000000];

	(void) context;
	if (n == SIGUSR1)
		var.i = var.i | (0x01 << var.bit);
	var.bit++;
	if ((var.bit == 8 && var.i == 0) || var.position == (1000000 - 1))
	{
		ft_print_message(str, info->si_pid);
		str[0] = 0;
		var.position = 0;
		var.bit = 0;
		var.i = 0;
	}
	else if (var.bit == 8)
	{
		str[var.position++] = var.i;
		str[var.position] = 0;
		var.bit = 0;
		var.i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
