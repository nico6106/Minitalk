/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:26:44 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/23 14:42:57 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

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
		ft_printf("Error\n");
	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error, there should not be any arguments\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID=%d\n", pid);
	while (argc == 1)
		sleep(1);
}

void	ft_handle(int n, siginfo_t *info, void *context)
{
	static int		i = 0;
	static int		position = 0;
	static int		bit = 0;
	static char		str[100000];
	int				j;

	(void) context;
	if (n == SIGUSR1)
		i = i | (0x01 << bit);
	bit++;
	if (bit == 8 && i == 0)
	{
		ft_putstr_fd(str, 1);
		j = -1;
		while (++j <= position)
			str[j] = 0;
		ft_putchar_fd('\n', 1);
		position = 0;
		bit = 0;
		i = 0;
	}
	else if (bit == 8)
	{
		str[position++] = i;
		bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	ft_clean_str(char *str, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		str[i] = 0;
		i++;
	}
	str[i] = 0;
}
