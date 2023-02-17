/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:59:42 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/15 10:10:41 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_linked(t_lst **lst)
{
	t_lst	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		ft_pop(lst);
		*lst = tmp;
	}
}

void	free_str(char **str, int error, int n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (error == -1)
		ft_putstr_fd("Error\n", 2);
	if (n == 1)
		exit (1);
	else if (n == 0)
		exit (0);
}
