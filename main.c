/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:58:51 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/08 09:03:44 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ---------------------------------------------------------------------------
*/

int		max(int a, int b, int c, int d)
{
	int tab[4];
	int i;
	int max;

	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
	tab[3] = d;
	i = 1;
	max = a;
	while (i < 4)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

/*
** ---------------------------------------------------------------------------
*/

int		min(int a, int b, int c, int d)
{
	int tab[4];
	int i;
	int min;

	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
	tab[3] = d;
	i = 1;
	min = a;
	while (i < 4)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

/*
** ---------------------------------------------------------------------------
*/

void	get_params_to_center_isoproject(int *x, int *y, t_map *map)
{
	t_point pt1;
	t_point pt2;
	t_point pt3;
	t_point pt4;

	pt1 = iso(map->tab[0]);
	pt2 = iso(map->tab[map->dim.length - 1]);
	pt3 = iso(map->tab[map->dim.length * map->dim.width - 1]);
	pt4 = iso(map->tab[map->dim.length * (map->dim.width - 1)]);
	*x = LEN / 2 - ((max(pt1.x, pt2.x, pt3.x, pt4.x) - min(pt1.x, pt2.x, pt3.x,\
								pt4.x)) / 2) - min(pt1.x, pt2.x, pt3.x, pt4.x);
	*y = WID / 2 - ((max(pt1.y, pt2.y, pt3.y, pt4.y) - min(pt1.y, pt2.y, pt3.y,\
								pt4.y)) / 2) - min(pt1.y, pt2.y, pt3.y, pt4.y);
}

/*
** ---------------------------------------------------------------------------
*/

void	get_params_to_center_parallelproject(int *x, int *y, t_map *map)
{
	t_point pt1;
	t_point pt2;
	t_point pt3;
	t_point pt4;

	pt1 = map->tab[0];
	pt2 = map->tab[map->dim.length - 1];
	pt3 = map->tab[map->dim.length * map->dim.width - 1];
	pt4 = map->tab[map->dim.length * (map->dim.width - 1)];
	*x = LEN / 2 - ((max(pt1.x, pt2.x, pt3.x, pt4.x) - min(pt1.x, pt2.x, \
					pt3.x, pt4.x)) / 2) - min(pt1.x, pt2.x, pt3.x, pt4.x);
	*y = WID / 2 - ((max(pt1.y, pt2.y, pt3.y, pt4.y) - min(pt1.y, pt2.y, \
					pt3.y, pt4.y)) / 2) - min(pt1.y, pt2.y, pt3.y, pt4.y);
}

/*
** ---------------------------------------------------------------------------
*/

void	ft_apply_homothetie(t_map *map, t_mlxparams *mlxparams)
{
	int	k;

	while (k * map->dim.width < mlxparams->width_img && k < 20)
		k++;
	homothetie(k, map);
}

/*
** ---------------------------------------------------------------------------
*/

void	fdf(t_map *map)
{
	t_mlxparams	*mlxparams;
	t_hook		hook_variables;

	if (!(mlxparams = malloc(sizeof(*mlxparams))))
	{
		perror("");
		exit(0);
	}
	fill_mlxparams(mlxparams);
	ft_apply_homothetie(map, mlxparams);
	get_params_to_center_isoproject(&hook_variables.proj_params[0].x, \
			&hook_variables.proj_params[0].y, map);
	get_params_to_center_parallelproject(&hook_variables.proj_params[1].x, \
			&hook_variables.proj_params[1].y, map);
	iso_proj(mlxparams, map, hook_variables.proj_params[0].x, \
			hook_variables.proj_params[0].y);
	hook_variables.mlxparams = mlxparams;
	hook_variables.map = map;
	mlx_key_hook(mlxparams->mlx_win, put, (void*)&hook_variables);
	mlx_loop(mlxparams->mlx_ptr);
}

/*
** ---------------------------------------------------------------------------
*/

int		main(int ac, char **av)
{
	int		fd;
	t_map	*map;

	if (!(fd = is_file_valid(ac, av)))
		return (0);
	if (!(map = malloc(sizeof(*map))))
	{
		perror("");
		return (0);
	}
	get_map(&fd, map, av[1]);
	close(fd);
	fdf(map);
	return (0);
}
