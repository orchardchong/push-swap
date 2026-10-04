/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:11:13 by ochong            #+#    #+#             */
/*   Updated: 2026/10/01 23:11:13 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	int	temp;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a) -> next == *stack_a)
		return;
	temp = (*stack_a) -> value;
	(*stack_a) -> value = (*stack_a) -> next -> value;
	(*stack_a) -> next -> value = temp;
	write (1, "sa\n", 3);
} 

void	sb(t_node **stack_b)
{
	int	temp;

	if (stack_b == NULL || *stack_b == NULL || (*stack_b) -> next == *stack_b)
		return;
	temp = (*stack_b) -> value;
	(*stack_b) -> value = (*stack_b) -> next -> value;
	(*stack_b) -> next -> value = temp;
	write (1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	int	temp_a;
	int	temp_b;

	if (stack_a != NULL || *stack_a != NULL || (*stack_a) -> next != *stack_a)
	{
		temp_a = (*stack_a) -> value;
		(*stack_a) -> value = (*stack_a) -> next -> value;
		(*stack_a) -> next -> value = temp_a;
	}
	if (stack_b != NULL || *stack_b != NULL || (*stack_b) -> next != *stack_b)
	{
		temp_b = (*stack_b) -> value;
		(*stack_b) -> value = (*stack_b) -> next -> value;
		(*stack_b) -> next -> value = temp_b;
		write (1, "ss\n", 3);
	}
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*first;

	if (stack_b == NULL || *stack_b == NULL)
		return;
	first = *stack_b;
	if (first->next == first)
		*stack_b = NULL;
	else
	{
		first->prev->next = first->next;
		first->next->prev = first->prev;
		*stack_b = first->next;
	}
	ft_lstadd_front(stack_a, first);
	write (1, "pa\n", 3);
}

void	pb(t_node **stack_b, t_node **stack_b)
{
	t_node	*first;

	if (stack_a == NULL || *stack_a == NULL)
		return;
	first = *stack_a;
	if (first->next == first)
		*stack_a = NULL;
	else
	{
		first->prev->next = first->next;
		first->next->prev = first->prev;
		*stack_a = first->next;
	}
	ft_lstadd_front(stack_b, first);
	write (1, "pb\n", 3);
}
