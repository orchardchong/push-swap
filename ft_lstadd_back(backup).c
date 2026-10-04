/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 23:14:24 by ochong            #+#    #+#             */
/*   Updated: 2026/08/10 21:35:59 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_node **head, t_node *new)
{
	t_node	*last;

	if (head == NULL || new == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*head)->prev;
	last->next = new;
	new->prev = last;
	new->next = (*head);
	(*head)->prev = new;
}

/*1 2  3 <- 1 '4'

1 <-> 2 <-> 3 <-> 1 (double circular)
1 -> 2 -> 3 -> 1 -> 2 -> 3(single circular)
1 -> 2 -> 3 (single linked list)
1 <-> 2 <-> 3 (double linked list)*/
