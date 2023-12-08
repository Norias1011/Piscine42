/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:20:42 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/07 12:24:54 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	nextsep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	if (c == '\0')
	{
		return (1);
	}
	return (0);
}

int	words_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (nextsep(str[i], charset) == 0 && nextsep(str[i + 1], charset) == 1)
		{
			count++;
		}
		i++;
	}
	return (count);
}

void	words_copy(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (nextsep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	split_word(char *str, char *charset, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (nextsep(str[i], charset) == 1)
		{
			i++;
		}
		else
		{
			j = 0;
			while (nextsep(str[i + j], charset) == 0)
			{
				j++;
			}
			tab[k] = (char *)malloc(sizeof(char) * (j + 1));
			words_copy(tab[k], str + i, charset);
			i = i + j;
			k++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		words;

	words = words_count(str, charset);
	tab = (char **)malloc(sizeof(char *) * (words +1));
	if (tab == NULL)
	{
		return (NULL);
	}
	split_word(str, charset, tab);
	tab[words] = 0;
	return (tab);
}

/*int main(int argc, char **argv) 
{
    char *str = "hello, world";
    char *charset = ", ";
    char **tab;

	tab = ft_split(str, charset);
	int i = 0;
	while (tab[i] != 0)
	{
		printf("%s\n" , tab[i]);
		i++;
	}
	return (0);
}*/
