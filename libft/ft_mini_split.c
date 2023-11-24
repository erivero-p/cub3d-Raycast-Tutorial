/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:13:22 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:36:47 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns an array of strings obtained by 
splitting ’s’ using the character ’c’ as a delimiter. The array must be
ended by a NULL pointer.*/

/*int i;     count 's'
int count; coutn 'words'
int w;     'word' yes(1) or no (0)*/

int	mini_count_word(char const *s, char c)
{
	int	i;
	int	count;
	int	w;
	int	equal;

	i = 0;
	count = 0;
	w = 0;
	equal = 0;
	while (s[i])
	{
		if (s[i] == c && s[i] != '\0')
		{
			w = 0;
			equal++;
		}
		else if (s[i] != c && w == 0 && (equal == 0 || equal == 1))
		{
			w = 1;
			count = count + 1;
		}
		i++;
	}
	return (count);
}

	/*int len; // lenght of 'words'
	int j;   // count of s*/

static int	mini_count_len(char *s, int *i, char c)
{
	int	len;
	int	j;

	len = 0;
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	j = *i;
	while (s[j] && (s[j] != c))
	{
		j++;
		len++;
	}
	return (len);
}

	/*int wordsize; //size of  'word'
	int k;        //count for 'word' (count of **)
	int q;        //count to 'write' 'words' (count of *)
	char *word;   // where 'words' are gonna be allocated*/

int	ft_aux_write(int q, char *s, int *i)
{
	q++;
	if (ft_is_equal(s[*i]))
		*i = *i + 1;
	return (q);
}

static int	mini_w_word(char *s, char **p, int *i, char c)
{
	int		wordsize;
	int		k;
	int		q;
	char	*word;

	wordsize = mini_count_len(s, i, c);
	q = 0;
	while (wordsize != 0)
	{
		word = (char *)ft_calloc(sizeof(char), (wordsize + 1));
		if (!word)
			return (1);
		k = 0;
		while (k < wordsize)
		{
			word[k++] = s[*i];
			*i = *i + 1;
		}
		p[q] = word;
		q = ft_aux_write(q, s, i);
		wordsize = ft_strlen(&s[*i]);
	}
	p[q] = NULL;
	return (0);
}

	//int i;      //nº od 'words'
	//char **str; //where substr is gonna be allocated.
	//int j;      //count for an error
	//int error;  //if there's an error, free memory

char	**ft_mini_split(char const *s, char c)
{
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)ft_calloc(sizeof(char *), mini_count_word(s, c) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (mini_count_word(s, c) == 1 && s[j] == c)
		j++;
	if (s[j] == '\0')
		return (NULL);
	j = 0;
	if (mini_w_word((char *)s, str, &j, c))
	{
		j = 0;
		while (str[j++])
			free(str[j]);
		free(str);
		return (NULL);
	}
	return (str);
}

/*void	ft_leaks(void)
{
	system("leaks -q a.out");
}

int main(void)
{
	atexit(ft_leaks);
	int		i;
	char	*str1;
	char	*str2;
	char	*str3;
	char	**split1;
	char	**split2;
	char	**split3;

	i = 0;
	str1 = "PAGER=less";
	str2 = "ABC=def=ghi=jkl";
	str3 = "LS_COLORS=di=1;36:ln=35:so=32:pi=33:ex=31:bd=34
	;46:cd=34;43:su=30;41:sg=30;46:tw=30;42:ow=30;43";
	split1 = ft_mini_split(str1, '=');
	split2 = ft_mini_split(str2, '=');
	split3 = ft_mini_split(str3, '=');
	while (split1[i])
	{
		printf("split1: %s\n", split1[i]);
		i++;
	}
	i = 0;
	while (split2[i])
	{
		printf("split2: %s\n", split2[i]);
		i++;
	}
	i = 0;
	while (split3[i])
	{
		printf("split: %s\n", split3[i]);
		i++;
	}
	ft_free_double_pointer(split1);
	ft_free_double_pointer(split2);
	ft_free_double_pointer(split3);
}*/
