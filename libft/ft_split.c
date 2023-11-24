/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:13:22 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:16 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns an array of strings obtained by 
splitting ’s’ using the character ’c’ as a delimiter. The array must be
ended by a NULL pointer.*/

/*int i;     count 's'
int count; coutn 'words'
int w;     'word' yes(1) or no (0)*/

int	count_word(char const *s, char c)
{
	int	i;
	int	count;
	int	w;

	i = 0;
	count = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c && s[i] != '\0')
		{
			w = 0;
			i++;
		}
		else if (s[i] != c && w == 0)
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

static int	count_len(char *s, int *i, char c)
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

static int	w_word(char *s, char **p, int *i, char c)
{
	int		wordsize;
	int		k;
	int		q;
	char	*word;

	wordsize = count_len(s, i, c);
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
		q++;
		wordsize = count_len(s, i, c);
	}
	p[q] = NULL;
	return (0);
}
	//probar si word[k] se puede dejar sin finalizar
	//probar si word_size se puede cambiar por la funcion

	//int i;      //nº od 'words'
	//char **str; //where substr is gonna be allocated.
	//int j;      //count for an error
	//int error;  //if there's an error, free memory

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)ft_calloc(sizeof(char *), count_word(s, c) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (count_word(s, c) == 1 && s[j] == c)
		j++;
	if (s[j] == '\0')
		return (NULL);
	j = 0;
	if (w_word((char *)s, str, &j, c) != 0)
	{
		j = 0;
		while (str[j++])
			free(str[j]);
		free(str);
		return (NULL);
	}
	return (str);
}
//i = count_word directamente en calloc
// w_word cambiar y sustituir por error