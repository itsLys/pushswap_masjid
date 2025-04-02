/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:43:09 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/18 07:43:18 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisdecimal(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (ft_isdigit(*str))
		str++;
	else
		return (0);
	while (ft_isdigit(*str))
		str++;
	return (!(*str));
}
