/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:58:51 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/07 23:37:25 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*---------------------------------------------------------------------------*/

void    ft_get_translation_param(int *x, int *y, t_map *map)
{
	t_point pt1;
	t_point pt2;
	t_point pt3;
	t_point pt4;
	t_point	win;

	win.x = 800;
	win.y = 800;
//	win = iso(win);
	printf("[pt3.x = %d]  [pt3.y = %d]\n",map->tab[map->dim.length * (map->dim.width - 1) + 1].x, map->tab[map->dim.length * (map->dim.width - 1) + 1].y);
	//printf("[pt1.x = %d]  [pt1.y = %d]\n", map->tab[0].x, map->tab[0].y);
	pt1 = iso(map->tab[0]);
	//printf("[pt1.x = %d]  [pt1.y = %d]\n", pt1.x, pt1.y);
	//printf("[pt2.x = %d]  [pt2.y = %d]\n", map->tab[map->dim.length - 1].x, map->tab[map->dim.length - 1].y);
	pt2 = iso(map->tab[map->dim.length - 1]);
	//printf("[pt2.x = %d]  [pt2.y = %d]\n", pt2.x, pt2.y);
	pt3 = iso(map->tab[map->dim.length * (map->dim.width - 1) + 1]);
	pt4 = iso(map->tab[map->dim.length * map->dim.width - 1]);
/*
	pt1 = map->tab[0];
	pt2 = map->tab[map->dim.length - 1];
	pt3 = map->tab[map->dim.length * (map->dim.width - 1) + 1];
	pt4 = map->tab[map->dim.length * map->dim.width - 1];
*/
	printf("[pt1.x = %d]  [pt1.y = %d]\n", pt1.x, pt1.y);
	printf("[pt2.x = %d]  [pt2.y = %d]\n", pt2.x, pt2.y);
	printf("[pt3.x = %d]  [pt3.y = %d]\n", pt3.x, pt3.y);
	printf("[pt4.x = %d]  [pt4.y = %d]\n", pt4.x, pt4.y);

	*y = (win.y - (pt1.y - pt4.y)) / 2;
	*x = (win.x - (pt2.x - pt3.x)) / 2;
	printf("[x = %d]\t[y = %d]\n", *x, *y);
}

/*---------------------------------------------------------------------------*/

void	fdf(t_map *map)
{
	t_mlxparams	*mlxparams;
	t_temp 	temp;
	t_point pt;
	//t_isomap	*isomap;

	if (!(mlxparams = malloc(sizeof(*mlxparams))))
	{
		perror("");
		exit(0);
	}
	fill_mlxparams(mlxparams);
	//iso_proj(mlxparams, *map);
	
	temp.mlxparams = mlxparams;
	temp.map = map;
	homothetie(20, map);
	pt.x = 200;
	pt.y = 0;

	ft_get_translation_param(&pt.x, &pt.y, map);
	translation_to_centre(0, pt.y, map);

	parallel_proj(mlxparams, *map);
	translation(pt.x + 200, 0, map);
	iso_proj(mlxparams, *map);

	mlx_key_hook(mlxparams->mlx_win, put, (void*)&temp);
	mlx_loop(mlxparams->mlx_ptr);
}

/*---------------------------------------------------------------------------*/

int 	main(int ac, char **av)
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
	get_map(fd, map);
	close (fd);
	fdf(map);
	return (0);
}
