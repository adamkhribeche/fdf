/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 00:14:10 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/08 08:44:38 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ***************************************************************************
*/

void	ft_change_z(t_hook *temp, t_map *map, int k)
{
	int row;
	int col;
	int	index;

	index = 0;
	row = 0;
	while (row < map->dim.length)
	{
		col = 0;
		while (col < map->dim.width)
		{
			if (k < 0)
				map->tab[index].z -= 2 * map->tab[index].v;
			else if (k > 0)
				map->tab[index].z += 2 * map->tab[index].v;
			index++;
			col++;
		}
		row++;
	}
	get_params_to_center_isoproject(&temp->proj_params[0].x, \
			&temp->proj_params[0].y, map);
	get_params_to_center_parallelproject(&temp->proj_params[1].x, \
			&temp->proj_params[1].y, map);
}

/*
** ***************************************************************************
*/

void	ft_draw(t_hook *temp, int nbr)
{
	void	(*func[2])(t_mlxparams *mlxparams, t_map *map, int x, int y);

	func[0] = iso_proj;
	func[1] = parallel_proj;
	ft_memset(temp->mlxparams->image, 0x0000, \
			temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
	func[nbr](temp->mlxparams, temp->map, temp->proj_params[nbr].x, \
			temp->proj_params[nbr].y);
}

int		put(int keycode, void *hook)
{
	static int			nbr;

	if (keycode == 53)
		exit(0);
	else if (keycode == 69)
		zoomin(((t_hook*)hook)->map);
	else if (keycode == 78)
		zoomout(((t_hook*)hook)->map);
	else if (keycode == 123)
		((t_hook*)hook)->proj_params[nbr].x -= 10;
	else if (keycode == 124)
		((t_hook*)hook)->proj_params[nbr].x += 10;
	else if (keycode == 125)
		((t_hook*)hook)->proj_params[nbr].y += 10;
	else if (keycode == 126)
		((t_hook*)hook)->proj_params[nbr].y -= 10;
	else if (keycode == 35)
		nbr = (nbr + 1) % 2;
	else if (keycode == 4)
		ft_change_z(((t_hook*)hook), ((t_hook*)hook)->map, +5);
	else if (keycode == 5)
		ft_change_z(((t_hook*)hook), ((t_hook*)hook)->map, -5);
	ft_draw(((t_hook*)hook), nbr);
	return (0);
}

/*
** ***************************************************************************
*/
