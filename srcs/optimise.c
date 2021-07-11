#include "push_swap.h"

static void	rb_ra_to_rr(t_operations *operations)
{
	char *content;
	char *nextcontent;
	t_operations *cleanup;

	while (operations && operations->next)
	{
		content = operations->content;
		nextcontent = operations->next->content;
		if (!(ft_strncmp(content, "rb", 2)) && !(ft_strncmp(nextcontent, "ra", 2)))
		{
			cleanup = operations->next;
			operations->content = "rr\n";
			operations->next = operations->next->next;
			cleanup->next = NULL;
			clear_operations(&cleanup);
		}
		operations = operations->next;
	}
}

void	rb_pa_rrb_to_sb_pa(t_operations *operations)
{
	char *content;
	char *secondcontent;
	char *thirdcontent;
	t_operations *cleanup;

	while (operations && operations->next && operations->next->next)
	{
		content = operations->content;
		secondcontent = operations->next->content;
		thirdcontent = operations->next->next->content;
		if (!ft_strncmp(content, "rb", 2) && !ft_strncmp(secondcontent, "pa", 2) && !ft_strncmp(thirdcontent, "rrb", 3))
		{
			cleanup = operations->next->next;
			operations->content = "sb\n";
			operations->next->next = operations->next->next->next;
			cleanup->next = NULL;
			clear_operations(&cleanup);
		}
		operations = operations->next;
	}
}

static int	remove_rrbrb(t_operations *operations)
{
	int count_changes;
	char *next;
	char *nextnext;
	t_operations *cleanup;

	count_changes = 0;
	while (operations && operations->next && operations->next->next)
	{
		next = operations->next->content;
		nextnext = operations->next->next->content;
		if (!(ft_strncmp(next, "rrb", 3)) && !(ft_strncmp(nextnext, "rb", 2)))
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
void	optimise(t_operations *operations)
{
	int changes;

	changes = 1;
	while (changes)
		changes = remove_rrbrb(operations);
	
	rb_ra_to_rr(operations);
	rb_pa_rrb_to_sb_pa(operations);
}