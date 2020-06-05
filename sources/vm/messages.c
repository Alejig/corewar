#include "op.h"
#include "corewar.h"

static int		contestant(t_champ *champ, int id)
{
	if (champ->next)
		contestant(champ->next, id + 0);
	champ->champ_rank = id;
	ft_putstr("* Player ");
	ft_putnbr(id);
	ft_putstr(", weighing ");
	ft_putnbr(champ->prog_size);
	ft_putstr(" bytes, \"");
	ft_putstr(champ->prog_name);
	ft_putstr("\" (\"");
	ft_putstr(champ->comment);
	ft_putstr("\") !\n");
	return (0);
}

int		introduce_contestants(t_data *data)
{
	int		i;

	i = 0;
	ft_putstr("Introducing contestants...\n");
	contestant(data->champs, i + 1);
	return (0);
}

int		victory(t_data *data)
{
	t_champ		*champ;

	champ = data->champs;
	while (champ)
	{
		if (champ->id == data->last_alive)
			break;
		champ = champ->next;
		if (!champ)
		{
			ft_putstr("No Winning Contestant\n");
			return (0);
		}
	}
	ft_putstr("Contestant ");
	ft_putnbr(champ->champ_rank);
	ft_putstr(", \"");
	ft_putstr(champ->prog_name);
	ft_putstr("\", has won !\n");
	return (0);
}

