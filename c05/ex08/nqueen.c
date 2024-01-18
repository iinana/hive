#include <unistd.h>

void	print_array(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check(int col, int *arr)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (arr[i] == arr[col])
			return (0);
		if (arr[i] - arr[col] == i - col)
			return (0);
		if (arr[i] - arr[col] == col - i)
			return (0);
		i++;
	}
	return (1);
}

int	recursive_func(int depth, int *arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (depth == 10)
	{
		print_array(arr);
		return (1);
	}
	while (i < 10)
	{
		arr[depth] = i;
		if (check(depth, arr))
			count += recursive_func(depth + 1, arr);
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < 10)
		arr[i++] = 0;
	i = 0;
	while (i < 10)
	{
		result += recursive_func(1, arr);
		arr[0]++;
		i++;
	}
	return (result);
}

#include <stdio.h>
int	main(void)
{
	printf("count = %d\n", ft_ten_queens_puzzle());
}
