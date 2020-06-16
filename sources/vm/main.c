/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:48:23 by vlaroque          #+#    #+#             */
/*   Updated: 2020/06/16 21:14:36 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "corewar.h"

int		finish_champs(t_data *data)
{
	t_champ		*champ;
	int			i;
	int			nbr_champs;
	int			rank;

	rank = 1;
	i = 1;
	nbr_champs = 0;
	champ = data->champs;
	while (champ)
	{
		champ->champ_rank = rank++;
		if (!(champ->n_option))
		{
			champ->id = i;
			i++;
		}
		nbr_champs++;
		champ = champ->next;
	}
	if (nbr_champs < 1)
		print_usage(data);
	if (nbr_champs > 4)
		print_error(data, 30);
	return (0);
}

int		init_data(t_data *data, int ac, char **av)
{
	data->ac = ac;
	data->av = av;
	data->max_cycles = CYCLE_TO_DIE;
	data->cycles_to_die = CYCLE_TO_DIE;
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;
	int			vic;

	op_bzero(&data, sizeof(t_data));
	init_data(&data, ac, av);
	init_corewar(&data, ac, av);
	finish_champs(&data);
	if (!data.visual_option)
		introduce_contestants(&data);
	mars_fill(&data);
	vic = battle(&data);
	if (vic)
		victory(&data);
	free_data(&data);
	return (0);
}
