/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:29:58 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/21 16:19:13 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_str_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
