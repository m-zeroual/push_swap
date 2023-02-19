/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:25:03 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/19 15:04:23 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_res(char *s, int n)
{
	ft_printf("%s\n", s);
	if (n == 1)
		exit (0);
}

void	free_p(char *p, int ex)
{
	free(p);
	if (ex == 1)
		exit (1);
}

void	check_correct_input(char *input)
{
	if (ft_strncmp(input, "sa\n", 3)
		&& ft_strncmp(input, "ra\n", 3)
		&& ft_strncmp(input, "rra\n", 4)
		&& ft_strncmp(input, "sb\n", 3)
		&& ft_strncmp(input, "rb\n", 3)
		&& ft_strncmp(input, "rrb\n", 4)
		&& ft_strncmp(input, "ss\n", 3)
		&& ft_strncmp(input, "rr\n", 3)
		&& ft_strncmp(input, "rrr\n", 4)
		&& ft_strncmp(input, "pb\n", 3)
		&& ft_strncmp(input, "pa\n", 3))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}

void	do_instraction(t_sort *s, char *input)
{
	check_correct_input(input);
	if (!ft_strncmp(input, "sa\n", 3))
		sa(&s->stack_a, 0);
	else if (!ft_strncmp(input, "ra\n", 3))
		ra(&s->stack_a, 0);
	else if (!ft_strncmp(input, "rra\n", 4))
		rra(&s->stack_a, 0);
	else if (!ft_strncmp(input, "sb\n", 3))
		sb(&s->stack_b, 0);
	else if (!ft_strncmp(input, "rb\n", 3))
		rb(&s->stack_b, 0);
	else if (!ft_strncmp(input, "rrb\n", 4))
		rrb(&s->stack_b, 0);
	else if (!ft_strncmp(input, "ss\n", 3))
		ss(&s->stack_a, &s->stack_b, 0);
	else if (!ft_strncmp(input, "rr\n", 3))
		rr(&s->stack_a, &s->stack_b, 0);
	else if (!ft_strncmp(input, "rrr\n", 4))
		rrr(&s->stack_a, &s->stack_b, 0);
	else if (!ft_strncmp(input, "pa\n", 3))
		pa(&s->stack_a, &s->stack_b, 0);
	else if (!ft_strncmp(input, "pb\n", 3))
		pb(&s->stack_a, &s->stack_b, 0);
	free(input);
}

void	read_inst(t_sort *s)
{
	int		check;
	char	input[2];
	char	*inst;

	inst = ft_strdup("");
	while (1)
	{
		input[0] = 0;
		input[1] = 0;
		check = read(0, input, 1);
		if (check == -1 || !check)
		{
			if (check == -1)
				free_p(inst, 1);
			return (free_p(inst, 3));
		}
		if (!ft_strncmp(input, "\n", 1))
		{
			inst = ft_strjoin(inst, input);
			do_instraction(s, inst);
			inst = ft_strdup("");
		}
		else
			inst = ft_strjoin(inst, input);
	}
}
