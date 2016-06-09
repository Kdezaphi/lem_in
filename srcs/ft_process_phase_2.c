/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_phase_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:33:18 by kdezaphi          #+#    #+#             */
/*   Updated: 2016/03/17 16:13:40 by kdezaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_link(t_anthill *anthill, char *name1, char *name2)
{
	int		i;
	int		j;
	int		err;

	i = -1;
	j = -1;
	err = 1;
	while (++i < anthill->nb_room)
		if (!ft_strcmp(anthill->room[i]->name, name1)
			|| !ft_strcmp(anthill->room[i]->name, name2))
		{
			if (j == -1)
				j = i;
			else
				break ;
		}
	if (i != anthill->nb_room)
	{
		anthill->nb_link++;
		anthill->link[i][j] = 1;
		anthill->link[j][i] = 1;
		err = 0;
	}
	return (err);
}

int			ft_process_phase_2(char *line, t_anthill *anthill)
{
	int		i;
	int		err;
	int		dash;
	char	**tab;

	err = 1;
	dash = 0;
	i = -1;
	while (line[++i])
		if (line[i] == '-')
			dash++;
	if (dash == 1)
	{
		tab = ft_strsplit(line, '-');
		if (tab[0] && tab[1] && !tab[2])
			err = ft_check_link(anthill, tab[0], tab[1]);
		ft_freetab(tab);
	}
	return (err);
}
