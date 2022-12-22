/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:28:04 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/22 14:50:15 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

//serveur_main.c
void	ft_handle_signal(int n);
char	*ft_upsize_str(char *init);

#endif
