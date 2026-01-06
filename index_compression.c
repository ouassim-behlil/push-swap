#include "./pushSwap.h"

static void	swap_values(int *a, int *b)
{
	if (a == b)
		return ;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

static int	lomuto_partition(int *arr, int low, int high)
{
	int		pivot;
	int		j;
	int		i;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_values(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_values(&arr[i + 1], &arr[j]);
	return (i + 1);
}

static void	quick_sort(int *arr, int low, int high)
{
	int		partition_point;

	if (low >= high)
		return ;
	partition_point = lomuto_partition(arr, low, high);
	quick_sort(arr, low, partition_point - 1);
	quick_sort(arr, partition_point + 1, high);
}

static int	binary_search(int *arr, int low, int high, int x)
{
	int		m;

	if (low > high)
		return (-1);
	m = low + (high - low) / 2;
	if (arr[m] == x)
		return (m);
	else if (arr[m] < x)
		return (binary_search(arr, m + 1, high, x));
	else
		return (binary_search(arr, low, m - 1, x));
}

bool	stack_indexing(t_stack *stack)
{
	int		*arr;
	t_node	*node;
	int		size;

	arr = stack_to_array(stack);
	if (!arr)
		return (false);
	size = stack->size;
	quick_sort(arr, 0, size - 1);
	node = stack->top;
	while (node)
	{
		node->index = binary_search(arr, 0, size - 1, node->value);
		node = node->next;
	}
	free(arr);
	return (true);
}
