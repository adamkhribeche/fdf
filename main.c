/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:58:51 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/07 18:06:09 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_translation_param(int *x, int *y, t_map *map)
{
	t_point pt1;
	t_point pt2;
	t_point pt3;
	t_point pt4;

	pt1 = iso(map->tab[0]);
	pt2 = iso(map->tab[map->dim.length - 1]);
	pt3 = iso(map->tab[map->dim.length * (map->dim.width - 1) + 1]);
	pt4 = iso(map->tab[map->dim.length * map->dim.width - 1]);

	*y = 350 - ((pt4.y - pt1.y) / 2);
	*x = 400 - ((pt2.x - pt3.x) / 2);
}

void	fdf(t_map *map)
{
	t_mlxparams	*mlxparams;
	t_temp 	temp;
	int		x;
	int		y;
	t_point	pt;

	pt.x = 100;
	pt.y = 0;
	if (!(mlxparams = malloc(sizeof(*mlxparams))))
	{
		perror("");
		exit(0);
	}
	fill_mlxparams(mlxparams);
	temp.mlxparams = mlxparams;
	temp.map = map;
	homothetie(20, map);
	//translation(500, 100, map);
	//ft_get_translation_param(&x, &y, map);
	translation(x, y, map);
	iso_proj(mlxparams, map);
	//parallel_proj(mlxparams, map);
	//printmap(*map);
	mlx_key_hook(mlxparams->mlx_win, put, (void*)&temp);
	mlx_loop(mlxparams->mlx_ptr);
}

int 	main(int ac, char **av)
{
	int		fd;
	t_map	*map;
//	t_map	map2;

	if (!(fd = is_file_valid(ac, av)))
		return (0);
	if (!(map = malloc(sizeof(*map))))
	{
		perror("");
		return (0);
	}
	get_map(fd, map);
	close (fd);
	//map2 = dupmap(map);
	//printf("%d\n", map2.dim.length);
	//printf("%d\n", map2.dim.width);
	//printmap(*map);
	fdf(map);
	return (0);
}
