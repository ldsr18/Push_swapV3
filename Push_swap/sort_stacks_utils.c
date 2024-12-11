/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:35:33 by jdecarro          #+#    #+#             */
/*   Updated: 2024/12/09 16:35:33 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot2(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*a != cheap && *b != cheap->target_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rrr2(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*a != cheap && *b != cheap->target_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap;

	cheap = find_cheapest_node(*a);
	if (cheap->above_median
		&& cheap->target_node->above_median)
		rot2(a, b, cheap);
	else if (!(cheap->above_median)
		&& !(cheap->target_node->above_median))
		rrr2(a, b, cheap);
	prep_for_p(a, cheap, 'a');
	prep_for_p(b, cheap->target_node, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_p(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min_node;

	min_node = find_min(*a);
	if (!min_node)
		return ;
	while ((*a)->nb != min_node->nb)
	{
		if (min_node->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
