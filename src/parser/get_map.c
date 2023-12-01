#include "../../inc/cub3D.h"

int	ft_get_max_len(char **matrix, int j)
{
	int	max;

	max = 0;
	while (matrix[j])
	{
		if (ft_strlen(matrix[j]) > max)
			max = ft_strlen(matrix[j]);
		j++;
	}
	return (max);
}
char	*ft_rectangle(char *str, int max)
{
	int len;

	len = ft_strlen(str);
}

char **ft_subarr(char **arr, int start, int len)
{
	char	**cpy;
	int		i;

	i = 0;
	if (len > ft_arrlen(arr))
		return (NULL);
	cpy = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	while (arr[start + i] && i < len)
	{
		cpy[i] = ft_strtrim(arr[start + i], "\n");
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

/* void	ft_rectang_map(char **matrix, int j, int len)
{

} */