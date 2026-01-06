#include "pushSwap.h"

size_t	ft_countwords(const char *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_get_next_word(const char **str, char c)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	while ((*str)[i] && (*str)[i] == c)
		i++;
	(*str) = (*str) + i;
	len = 0;
	while ((*str)[len] && (*str)[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while ((*str)[i] && (*str)[i] != c)
	{
		word[i] = (*str)[i];
		i++;
	}
	word[i] = '\0';
	*str = *str + i;
	return (word);
}

static void	free_words(char **words, size_t count)
{
	while (count--)
		free(words[count]);
	free(words);
}

char	**ft_split(const char *s, char c)
{
	size_t		wordcount;
	size_t		i;
	char		*word;
	char		**words;

	i = 0;
	wordcount = ft_countwords(s, c);
	words = malloc((wordcount + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (i < wordcount)
	{
		word = ft_get_next_word(&s, c);
		if (!word)
			return (free_words(words, i), NULL);
		words[i] = word;
		i++;
	}
	words[i] = NULL;
	return (words);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
