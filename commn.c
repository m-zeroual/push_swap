/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:01:49 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/12 18:52:02 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_in_ra_rb(t_count *commn)
{
	int	max;

	if (commn->ra > commn->rb)
	{
		commn->rr = commn->rb;
		max = commn->ra;
		commn->ra = commn->ra - commn->rb;
		commn->rb = 0;
		return (max);
	}
	commn->rr = commn->ra;
	max = commn->rb;
	commn->rb = commn->rb - commn->ra;
	commn->ra = 0;
	return (max);
}

int	max_in_rra_rrb(t_count *commn)
{
	int	max;

	if (commn->rra > commn->rrb)
	{
		commn->rrr = commn->rrb;
		max = commn->rra;
		commn->rra = commn->rra - commn->rrb;
		commn->rrb = 0;
		return (max);
	}
	commn->rrr = commn->rra;
	max = commn->rrb;
	commn->rrb = commn->rrb - commn->rra;
		commn->rra = 0;
	return (max);
}
