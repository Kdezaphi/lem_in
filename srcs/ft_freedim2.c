/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:57:12 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/03/17 10:57:23 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_freedim2(void **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(tab[i++]);
	free(tab);
}
