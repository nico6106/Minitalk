/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:29:08 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/27 12:13:00 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/client_bonus.h"

int	g_status;

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_handle_signal;
	sigaddset(&sa.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_quit_message("Error with signal\n");
	pid = 0;
	if (argc != 3)
		ft_quit_message("Error with the arguments entered\n");
	if (ft_extract_pid(argv[1], &pid) == 0)
		ft_quit_message("Error with the PID entered\n");
	g_status = 0;
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

void	ft_handle_signal(int n, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	g_status = 1;
	if (n == SIGUSR2)
		ft_putstr_fd("Message received by the server\n", 1);
}

int	ft_send_char(char c, int pid)
{
	int					i;
	int					retour;

	i = 1;
	retour = 0;
	while (i <= 8)
	{
		if ((c << (8 - i) & 128) >> (7) == 1)
			retour = kill(pid, SIGUSR1);
		else
			retour = kill(pid, SIGUSR2);
		if (retour == -1)
			ft_quit_wrong_pid();
		i++;
		while (g_status == 0)
			;
		g_status = 0;
	}
	return (0);
}
