/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:26:44 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/22 15:22:38 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	void 	ft_handle_signal(int sig);
	struct sigaction sa;

	sa.sa_handler = ft_handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) 
	{
        ft_printf("Error\n");
    }
	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error, there should not be any arguments\n");
		return (1);
	}
	pid = getpid();
	ft_printf("pid='%d'\n", pid);
	//signal(SIGUSR1, ft_handle_signal);
	//signal(SIGUSR2, ft_handle_signal);
	while (argc == 1)
	{
		pause();
	}
}

void	ft_handle_signal(int n)
{
	static int		i = 0;
	static int		position = 0;
	static int		nb = 1;
	static int		bit = 0;
	static char		*str = NULL;

	if (!str)
	{
		str = malloc((50 + 1) * sizeof(char));
		if (!str)
			exit (0);
		str[50] = '\0';
	}
	if (n == SIGUSR1)
		i = i | (0x01 << bit);
	bit++;
	if (bit == 8 && i == 0)
	{
		/*exit, et affichage*/
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
		position = 0;
		bit = 0;
		i = 0;
	}
	else if (bit == 8)
	{
		str[position] = i;
		position++;
		bit = 0;
		i = 0;
	}
	if (position == 50 * nb)
	{
		nb++;
		str = ft_upsize_str(str);
	}
}

char	*ft_upsize_str(char *init)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(init);
	str = malloc((len + 50 + 1) * sizeof(char));
	str[len + 50] = '\0';
	if (!str)
	{
		free(init);
		exit (0);
	}
	while (init[i])
	{
		str[i] = init[i];
		i++;
	}
	free(init);
	return (str);
}
