# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 20:11:19 by mzeroual          #+#    #+#              #
#    Updated: 2023/02/19 16:07:20 by mzeroual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c\
		push_swap.c\
		len.c\
		pop_push_function.c\
		rule1.c\
		rule2.c\
		rule3.c\
		utils.c\
		sort_1_2_3_4_5.c\
		move_top.c\
		min_or_max.c\
		commn.c\
		before.c\
		push_min_to_b.c\
		ft_check_errors.c\
		free_str.c

		
SRCB =  checker.c\
		utils_checker.c\
		len.c\
		push_swap.c\
		pop_push_function.c\
		rule1.c\
		rule2.c\
		rule3.c\
		utils.c\
		sort_1_2_3_4_5.c\
		move_top.c\
		min_or_max.c\
		commn.c\
		before.c\
		push_min_to_b.c	\
		ft_check_errors.c\
		free_str.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJ) 
	@make -C libft
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

clean : 
	@make clean -C libft
	@make clean -C ft_printf
	@$(RM) $(OBJ)
	@$(RM) $(OBJB)
fclean : clean
	@$(RM) libft/libft.a
	@$(RM) ft_printf/libftprintf.a
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
re : fclean all

bonus : $(BONUS)

$(BONUS): $(OBJB) 
		@make -C libft
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJB) libft/libft.a ft_printf/libftprintf.a -o $(BONUS)
PHONY : all $(NAME) $(BONUS) clean fclean re bonus
