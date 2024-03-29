/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:16:52 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/07 23:06:05 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*****************************************************************************/

void	ft_zoomin(t_mlxparams mlxparams, t_map *map, t_drowparams *param)
{
	int	map_len = map->dim.width * map->dim.length;
	int	index;
	int x;
	int y;

	//	param->zoom;
	//	printf("zoom =%d;\n", param->zoom);
	while (index < map_len)
	{
		map->tab[index].x++;
		map->tab[index].y++;
		//		printf("tab[%d].x = %d\ttab[%d].y = %d\ttab[%d].z = %d;\n", index,  map->tab[index].x, index, map->tab[index].y, index, map->tab[index].z);
		index++;
	}
	printf("index == %d;\n", index);
	//	printmap(*map);
	parallel_proj(&mlxparams, map, x, y);
}

int put(int keycode, void *hook_variables)
{
	t_hook_variables *hook_variables1 = (t_hook_variables*)hook_variables;
	t_map *map = hook_variables1->map;

	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
	{
		zoom(map);
		ft_memset(hook_variables1->mlxparams->image, 0x0000, hook_variables1->mlxparams->length_img * hook_variables1->mlxparams->width_img * 4);
		parallel_proj(hook_variables1->mlxparams, map, hook_variables1->proj_params[1].x, hook_variables1->proj_params[1].y);
	}
	return (0);
}

/*****************************************************************************/

void	ft_zoomout(t_mlxparams mlxparams, t_map *map, t_drowparams *param);

/*
void	ft_move_left(t_mlxparams *mlxparams, t_map *map, t_drowparams *param)
{
	//printf("start.\n");
	//printf("[width = %d] [length = %d]\n", map->dim.width, map->dim.length);
	int	map_len = map->dim.width * map->dim.length;
	//printf("maplen = %d\n", map_len);
	int	index;

	index = 0;
	while (index < map_len)
	{
		//printf("befor [maplen = %d] [index = %d] [x = %d]\n", map_len, index, map->tab[index].x);
		map->tab[index] = translation(0, 0, *map->tab[index]);

		//printf("after [maplen = %d] [index = %d] [x = %d]\n", map_len, index, map->tab[index].x);
		//		printf("map_len == %d;\n", map_len);
		index++;
	}
	parallel_proj(mlxparams, *map);
}
int put(int keycode, void *vartemp)
{
	t_vars *vars = (t_vars*)vartemp;
	printf("keyCode == %d;\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)// move left
	{
		//	printf("before move left;\n");
		ft_move_left(vars->mlxparams, vars->map, vars->drawparams);
	}
	//printf("end of put;\n");
		else if (keycode == 78)
		ft_zoomout(*vars->mlxparams, vars->map, vars->drawparams);
		else if (keycode == 69)
		ft_zoomin(*vars->mlxparams, vars->map, vars->drawparams);
		else if (keycode == 124)// move right
		ft_move_right(mlxparams, map);
		else if (keycode == 125)// move down
		ft_move_down(mlxparams, map);
		else if (keycode == 126)// move up
		ft_move_up(mlxparams, map);
	
	return (0);
}
*/
