/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 19:21:00 by ochong            #+#    #+#             */
/*   Updated: 2026/10/03 19:21:00 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_separator(char c)
{
	if ((c == ' ') || (c >= 9 && c <= 13)) 
		return (1);
	return (0);
}

static int	count_word(char const *s)
{
	int	count;
	int	i;
	int	word;

	count = 0;
	i = 0;
	word = 0;
	while (s[i])
	{
		if (is_separator(s[i]))
			word = 0;
		else if (word == 0)
		{
			word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static void	*free_memory(char **arr, int nword)
{
	while (nword > 0)
	{
		nword--;
		free(arr[nword]);
	}
	free(arr);
	return (NULL);
}

static char	*build_word(char const *s, int start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**fill_arr(char **arr, char const *s)
{
	int	i;
	int	box;
	int	start;

	i = 0;
	box = 0;
	while (s[i])
	{
		while (s[i] && is_separator(s[i]))
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && !is_separator(s[i]))
			i++;
		arr[box] = build_word(s, start, i - start);
		if (!arr[box])
			return (free_memory(arr, box));
		box++;
	}
	arr[box] = NULL;
	return (arr);
}

char	**ft_split(char const *s)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc((count_word(s) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_arr(arr, s));
}

/*#include <stdio.h>

int main(void)
{
	char **result;
	int i;

	// 1. Run your function!
	result = ft_split("xxxhappyxxxbirTHDAY", 'x');

	// 2. Protect against a total failure
	if (!result)
	{
		printf("Error: ft_split returned NULL\n");
		return (1);
	}

	// 3. Loop through the array, print the words, and free them
	i = 0;
	while (result[i] != NULL)
	{
		printf("Word [%d]: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}*/
