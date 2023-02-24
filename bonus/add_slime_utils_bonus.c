#include "so_long_bonus.h"

void	*moove_s(t_data *data)
{
	static int	on = 0;

	if (on == 1)
	{
		on = 0;
		return (data->image->slime2);
	}
	else if (on == 0)
	{
		on = 1;
		return (data->image->slime1);
	}
	else
		return (data->image->slime1);
}
