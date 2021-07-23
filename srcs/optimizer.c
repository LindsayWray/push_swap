/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:42:32 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:42:35 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rb_ra_to_rr(t_operations *operations)
{
	char			*content;
	char			*nextcontent;
	t_operations	*cleanup;

	while (operations && operations->next)
	{
		content = operations->content;
		nextcontent = operations->next->content;
		if (ft_strequal(content, "rb") && ft_strequal(nextcontent, "ra"))
		{
			cleanup = operations->next;
			operations->content = "rr";
			operations->next = operations->next->next;
			cleanup->next = NULL;
			clear_operations(&cleanup);
		}
		operations = operations->next;
	}
}

void	rb_pa_rrb_to_sb_pa(t_operations *operations)
{
	char			*content;
	char			*secondcontent;
	char			*thirdcontent;
	t_operations	*cleanup;

	while (operations && operations->next && operations->next->next)
	{
		content = operations->content;
		secondcontent = operations->next->content;
		thirdcontent = operations->next->next->content;
		if (ft_strequal(content, "rb") && ft_strequal(secondcontent, "pa")
			&& ft_strequal(thirdcontent, "rrb"))
		{
			cleanup = operations->next->next;
			operations->content = "sb";
			operations->next->next = operations->next->next->next;
			cleanup->next = NULL;
			clear_operations(&cleanup);
		}
		operations = operations->next;
	}
}

static int	remove_rrbrb(t_operations *operations)
{
	int				count_changes;
	char			*next;
	char			*nextnext;
	t_operations	*cleanup;

	count_changes = 0;
	while (operations && operations->next && operations->next->next)
	{
		next = operations->next->content;
		nextnext = operations->next->next->content;
		if (ft_strequal(next, "rrb") && ft_strequal(nextnext, "rb"))
		{
			cleanup = operations->next;
			operations->next = operations->next->next->next;
			cleanup->next->next = NULL;
			clear_operations(&cleanup);
			count_changes++;
		}
		operations = operations->next;
	}
	return (count_changes);
}

void	sb_sa_to_ss(t_operations *operations)
{
	char			*content;
	char			*secondcontent;
	t_operations	*cleanup;

	while (operations && operations->next)
	{
		content = operations->content;
		secondcontent = operations->next->content;
		if (ft_strequal(content, "sb") && ft_strequal(secondcontent, "sa"))
		{
			cleanup = operations->next;
			operations->content = "ss";
			operations->next = operations->next->next;
			cleanup->next = NULL;
			clear_operations(&cleanup);
		}
		operations = operations->next;
	}
}

void	optimizer(t_operations *operations)
{
	int	changes;

	changes = 1;
	while (changes)
		changes = remove_rrbrb(operations);
	rb_ra_to_rr(operations);
	rb_pa_rrb_to_sb_pa(operations);
	sb_sa_to_ss(operations);
}
