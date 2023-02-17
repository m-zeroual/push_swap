/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:08:29 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/15 20:13:36 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_check
{
	int	index_a;
	int	index_b;
}	t_check;

typedef struct s_count
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
}	t_count;

typedef struct s_lst
{
	int				number;
	struct s_lst	*next;
}	t_lst;

typedef struct s_sort
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_check	best;
	int		move_stack_a;
	int		move_stack_b;
	int		move;
	char	a;
	char	b;
}	t_sort;

// push and pop function//
t_lst		*new_lst(int num);
int			lst_size(t_lst *lst);
void		ft_push(t_lst **lst, t_lst *new);
int			ft_pop(t_lst **lst);

// file utils.c
t_count		*count_in_b(t_sort *s, int num);
void		best_move(t_sort *s);

// file utils_1
void		sa(t_lst **list_a, int n);
void		sb(t_lst **list_b, int n);
void		ss(t_lst **list_a, t_lst **list_b, int n);
void		pa(t_lst **list_a, t_lst **list_b, int n);
void		pb(t_lst **list_a, t_lst **list_b, int n);

// file utils_2
void		ra(t_lst **list_a, int n);
void		rb(t_lst **list_b, int n);
void		rr(t_lst **list_a, t_lst **list_b, int n);

// file utils_3
void		rra(t_lst **list_a, int n);
void		rrb(t_lst **list_b, int n);
void		rrr(t_lst **list_a, t_lst **list_b, int n);

// ---- sort_1_2_3_4_5.c sort function ---
void		sort_two(t_sort *s);
void		sort_three(t_sort *s);
void		sort_four(int pos, t_sort *s);
void		sort_five(int pos, t_sort *s);
int			search_min(t_lst *list);

// move_top.c 
void		move_top(t_sort *s, t_count *best);
int			count_move(t_lst **list, int pos, char *c);
int			get_index(t_lst *list, int min);
int			get_value(t_lst *list, int index);
void		move_min_top(t_lst **list, int index);

// min_or_max.c 
int			get_min_or_max(t_lst **list, int num);

// push_min_to_b.c
void		push_min_to_b(t_sort *s, int value);

// commn.c
int			max_in_ra_rb(t_count *commn);
int			max_in_rra_rrb(t_count *commn);

// file before.c
int			before(t_lst *list);

// file ft_check_errors.c
char		**ft_joinargs(int ac, char **av);
void		ft_check_digit(char **str);

// free_str.c
void		free_str(char **str, int error, int n);
void		free_linked(t_lst **lst);

// file push_swap.c
void		fill_stack_a(t_sort *s, char **str);
void		sort(t_sort *s);
int			is_sorted(t_lst *list);
void		push_swap(t_sort *s, int ac, char **av);

// utils_checker.c
void		free_p(char *p, int ex);
void		print_res(char *s, int n);
void		ft(t_sort *s);
void		do_instraction(t_sort *s, char *input);
void		check_correct_input(char *input);

#endif
