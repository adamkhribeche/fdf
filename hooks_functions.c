/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:16:52 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/07 23:37:24 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


//		printf("tab[%d].x = %d\ttab[%d].y = %d\ttab[%d].z = %d;\n", index,  map->tab[index].x, index, map->tab[index].y, index, map->tab[index].z);
/*****************************************************************************/
/*
   typedef struct s_temp
   {
   mlxparams;
   map;
   point[2];

   }				t_temp
*/

void	ft_change_z(t_map *map, int	k)
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
			if (map->tab[index].z != 0)
				map->tab[index].z += k;
			index++;
			col++;
		}
		row++;
	}
}

int put(int keycode, void *temp1)
{
	t_hook_variables *temp = (t_temp*)temp1;
	t_map *map = temp->map;
	static int nbr;

	void	(*func[2])(t_mlxparams *mlxparams, t_map map);
	func[0] = iso_proj;
	func[1] = parallel_proj;

	if (keycode == 53)
		exit(0);
	else if (keycode == 69)
	{
		zoomin(map);
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 78)
	{
		zoomout(map);
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 123)
	{
		//move left
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		temp->point[nbr].x -= 5;
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 124)
	{
		//move right
		temp->point[nbr].x += 5;
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 125)
	{
		//move down
		temp->point[nbr].y += 5;
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 126)
	{
		//move up
		temp->point[nbr].y -= 5;
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 35)
	{
		nbr = (nbr + 1) % 2;
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 4)
	{
		// scroll up => z++;
		ft_change_z(map, +4);
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 5)
	{
		// scroll down => z--;
		ft_change_z(map, -4);
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	return (0);
}



/*****************************************************************************/
