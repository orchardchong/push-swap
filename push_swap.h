/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 22:43:19 by ochong            #+#    #+#             */
/*   Updated: 2026/09/30 22:43:19 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int	value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_b);
void	ft_lstadd_front(t_list **head, t_list *new);
int		is_num(char *str);
long	ft_atol(const char *str);
int		check_duplicate(t_node **stack_a, int num);

#endif

