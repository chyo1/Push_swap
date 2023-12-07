
#include "push_swap.h"

void	order_excep(t_node **a, t_node **b, int order, int which)
{
	// assemble divided in 2 to 6
	if (order == ASC) // ㅈㅈㅇ
	{
		order_under_6(a, b, 2, ASC); 	//  1 bottom_a  ASC
		order_under_6(a, b, 2, ASC); 	//  2 top_a     DESC
		order_under_6(a, b, 2, ASC); 	//  3 bottom_b  ASC
		exep_merge_to_b(a, b, ASC, which);
	}
	else // ㅇㅇㅈ
	{
		order_under_6(a, b, 2, DESC); 	// bottom_a  DESC
		order_under_6(a, b, 2, DESC); 	//  top_a    ASC
		order_under_6(a, b, 2, DESC); 	//  bottom_b DESC
		exep_merge_to_b(a, b, DESC, which);
	}
}

void	init_div_exep(t_node **a, t_node **b, int cnt, int order)
{
	// change 4 4 6 -> 4 5 5
	if (cnt == 14)
	{
		order_under_6(a, b, 4, ASC);
		if (order == ASC) // ㅇㅇㅈ
			order_under_6(a, b, 5, DESC);
		else if (order == DESC) // ㅇㅈㅈ
			order_under_6(a, b, 5, ASC);
		order_under_6(a, b, 5, DESC);
		return ;
	}
	// 5 5 6
	else if (cnt == 16)
	{
		order_under_6(a, b, 5, ASC);
		if (order == ASC) // ㅇㅇㅈ
			order_under_6(a, b, 5, DESC);
		else if (order == DESC) // ㅇㅈㅈ
			order_under_6(a, b, 5, ASC);
		return (order_excep(a, b, DESC, 16));
	}
	// 5 6 6
	else if (cnt == 17)
	{
		order_under_6(a, b, 5, ASC);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 16));
	}
	// 6 6 6
	else if (cnt == 18)
	{
		order_excep(a, b, ASC, 17);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 16));
	}
	// 17 17 18
	else if (cnt == 53)
	{
		case_53(a, b, order, cnt);
		return ;
	}

// Is it used in exception case?
	// if (cnt < 6)
	// {
	// 	order_under_6(a, b, cnt, order);
	// 	return ;
	// }

	init_div_exep(a, b, cnt / 3, ASC);
	if (order == ASC) // ㅇㅇㅈ
		init_div_exep(a, b, cnt / 3, DESC);
	else if (order == DESC) // ㅇㅈㅈ
		init_div_exep(a, b, cnt / 3, ASC);
	return (init_div_exep(a, b, cnt - 2 * (cnt / 3), DESC));
}

void	case_53(t_node **a, t_node **b, int order, int cnt)
{
	if (cnt == 17)
	{
		order_under_6(a, b, 5, ASC);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 17));
	}
	else if (cnt == 18)
	{
		order_excep(a, b, ASC, 17);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 17));
	}
	else if (cnt == 19) // last 18
	{
		order_excep(a, b, ASC, 17);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 16));
	}
	else if (cnt == 53)
	{
		case_53(a, b, ASC, 17);
		if (order == ASC)
			case_53(a, b, DESC, 18);
		else
			case_53(a, b, ASC, 18);
		// if (is_last_div(*a))
			return (case_53(a, b, DESC, 19));
		// else 
		// 	return (case_53(a, b, DESC, 18));
	}

	// if (cnt < 6)
	// 	return (order_under_6(a, b, cnt, order));

	// init_div_exep(a, b, cnt / 3, ASC);
	// if (order == ASC) // ㅇㅇㅈ
	// 	init_div_exep(a, b, cnt / 3, DESC);
	// else if (order == DESC) // ㅇㅈㅈ
	// 	init_div_exep(a, b, cnt / 3, ASC);
	// return (init_div_exep(a, b, cnt - 2 * (cnt / 3), DESC));
}

void	exep_merge_to_b(t_node **a, t_node **b, int order, int which)
{
	int	i;

	i = 0;
	// bottom_b -> top_a -> bottom_a
	while (i < 6)
	{
		(*b)->start = FALSE;
		(*b)->end = FALSE;

		// start = true
		if (i == 0 || i == 2 || i == 5)
			(*b)->start = TRUE;
		// end = true
		else if (i == 1 || i == 3 || i == 4)
			(*b)->end = TRUE;

		// bottom_b
		if (i < 2)
			rotate(a, b, 'b');
		// top_a
		else if (i < 4)
			push_a(a, b);
		// bottom_a
		else
		{
			push_a(a, b);
			rotate(a, b, 'a');
		}
		i++;
	}

	if (order == ASC)
		exep_asc_to_b(a, b, which);
	// desc
	else
		exep_desc_to_b(a, b, which);

	// reverse flag
	t_node *last = *b;
	while (last->end != TRUE)
		last = last->next;
	last->end = FALSE;
	last->start = TRUE;
	(*b)->start = FALSE;
	(*b)->end = TRUE;
}

