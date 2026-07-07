#include "main.h"
#include <stdlib.h>

/**
 * word_count - counts words in a string
 * @str: string to count
 *
 * Return: number of words
 */
int word_count(char *str)
{
	int i, count;

	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	return (count);
}

/**
 * free_words - frees an array of words
 * @words: array of words
 * @count: number of words allocated
 *
 * Return: nothing
 */
void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
}

/**
 * fill_word - copies one word into a new string
 * @str: source string
 * @start: start index
 * @end: end index
 *
 * Return: pointer to new word, or NULL if it fails
 */
char *fill_word(char *str, int start, int end)
{
	char *word;
	int i, len;

	len = end - start;
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		word[i] = str[start + i];
	word[i] = '\0';

	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of words, or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int i, start, index, count;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	count = word_count(str);
	if (count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	index = 0;
	start = -1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && start == -1)
			start = i;
		if ((str[i] == ' ' || str[i + 1] == '\0') && start != -1)
		{
			if (str[i] == ' ')
				words[index] = fill_word(str, start, i);
			else
				words[index] = fill_word(str, start, i + 1);
			if (words[index] == NULL)
			{
				free_words(words, index);
				return (NULL);
			}
			index++;
			start = -1;
		}
	}
	words[index] = NULL;

	return (words);
}
