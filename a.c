/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:53:07 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/07 16:09:40 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void ff(int a, int *p);


int main()
{
	int a = 3;
	int *p = &a;
	void *v;

	v = &a;
	ff(a, p);
}

void ff(int a, int *p)
{
	printf("%d\n", *p);
	printf("%d\n", a);
}
