/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:29:41 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 15:29:42 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sorted(t_data *data)
{
	int		i;
	int		j;
	t_stack	*node;

	data->sorted = malloc(sizeof(int) * data->size);
	node = *data->stack_a;
	i = 0;
	while (i < data->size)
	{
		data->sorted[i++] = node->value;
		node = node->next;
	}
	i = 0;
	while (i < data->size - 1)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->sorted[i] > data->sorted[j])
				ft_swap(data->sorted + i, data->sorted + j);
			j++;
		}
		i++;
	}
}

void	set_index(t_data *data)
{
	int		i;
	t_stack	*node;

	init_sorted(data);
	i = 0;
	node = *data->stack_a;
	while (i < data->size)
	{
		node = *data->stack_a;
		while (data->sorted[i] != node->value)
			node = node->next;
		node->index = i;
		i++;
	}
}

void	put_elemnt_index_first(int position, char stack_type, t_data *data)
{
	t_stack	**stack;
	int		i;

	stack = NULL;
	if (stack_type == 'a')
		stack = data->stack_a;
	else if (stack_type == 'b')
		stack = data->stack_b;
	i = 0;
	if (position < stack_size(*stack) / 2 - 1)
	{
		while (i++ < position)
			stack_rotate(stack_type, data);
	}
	else
	{
		while (i++ < stack_size(*stack) - position)
			stack_reverse_rotate(stack_type, data);
	}
}

void	merge_back(t_data *data)
{
	int		position;
	t_stack	*largest;

	while (stack_size(*data->stack_b))
	{
		largest = find_highest(*data->stack_b);
		position = get_position(largest->index, *data->stack_b);
		put_elemnt_index_first(position, 'b', data);
		pa(data);
	}
}

void	push_chunk_b(t_data *data)
{
	t_stack	**head_a;
	t_stack	**head_b;

	head_a = data->stack_a;
	head_b = data->stack_b;
	while (*head_a)
	{
		if ((*head_a)->index <= data->min)
		{
			pb(data);
			if (stack_size(*head_b) > 1)
				rb(data);
			set_data(data);
		}
		else if ((*head_a)->index <= data->max)
		{
			pb(data);
			if (stack_size(*head_b) > 2
				&& (*head_b)->index < (*head_b)->next->index)
				sb(data);
			set_data(data);
		}
		else
			ra(data);
	}
}
