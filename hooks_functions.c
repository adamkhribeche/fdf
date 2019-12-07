/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:16:52 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/07 23:49:48 by mzaboub          ###   ########.fr       */
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
	int x;
	int y;

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

int put(int keycode, void *hook_variables)
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
		// change projection
		nbr = (nbr + 1) % 2;
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		func[nbr](temp->mlxparams, *map, temp->proj_params[nbr].x, temp->proj_params[nbr].y);
	}
	else if (keycode == 4)
	{
		// increace z
		ft_change_z(map, +4);
		ft_memset(hook_variables1->mlxparams->image, 0x0000, hook_variables1->mlxparams->length_img * hook_variables1->mlxparams->width_img * 4);
		parallel_proj(hook_variables1->mlxparams, map, hook_variables1->proj_params[1].x, hook_variables1->proj_params[1].y);
	}
	else if (keycode == 5)
	{
		// decreace z
		ft_change_z(map, -4);
		ft_memset(hook_variables1->mlxparams->image, 0x0000, hook_variables1->mlxparams->length_img * hook_variables1->mlxparams->width_img * 4);
		parallel_proj(hook_variables1->mlxparams, map, hook_variables1->proj_params[1].x, hook_variables1->proj_params[1].y);
	}
	return (0);
}

/*****************************************************************************/
