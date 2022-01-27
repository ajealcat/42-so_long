/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_slime_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:17:13 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/27 15:25:44 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
