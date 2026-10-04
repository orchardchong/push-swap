/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metrics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 19:11:56 by ochong            #+#    #+#             */
/*   Updated: 2026/10/04 19:11:56 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_metrics(t_node **stack_a)
{
	t_node	*current;
	t_node	*nextdigit;
	float	mistakes;
	float	total_pairs;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == *stack_a)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;

	current = *stack_a;
	do
	{
		nextdigit = current->next;
		while (nextdigit != *stack_a)
		{
			total_pairs++;
			if (current->value > nextdigit->value)
				mistakes++;
			nextdigit = nextdigit->next;
		}
		current = current->next;
	}
	while (current != *stack_a);
	return (mistakes / total_pairs);
}
