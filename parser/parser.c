/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:45:05 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/12 14:03:36 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	input_copy(char *dst, char *src)
{
	char quote;

	while (*src)
	{
		if (*src == ' ' && (*(src + 1) == ' ' || *(src + 1) == '\0'))
			src++;
		else if (*src == '"' || *src == '\'')
		{
			quote = *(src++);
			while (*src != quote)
				*(dst++) = *(src++);
			src++;
		}
		else
			*(dst++) = *(src++);
	}
	*dst = '\0';
}

static int	input_len(char *str)
{
	int i;
	char quote;

	i = - 1;
	while (*str)
	{
		if (*str == ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0'))
			str++;
		else if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str != quote && *str)
			{
				i++;
				str++;
			}
			if (!*str)
				return (-1);
			str++;
		}
		else if (str++)
			i++;
	}
	return (i);
}

static char	*input_cleaner(char *str)
{
	int len;
	char *clean_input;

	len = input_len(str);
	if (len == -1)
		return (0);
	clean_input = (char *)malloc((len + 1) * sizeof(char));						//malloc
	if (!clean_input)
		return (0);
	input_copy(clean_input, str);
	return (clean_input);
}

int	parser(char *user_input)
{
	char *clean_input = input_cleaner(user_input);
	if (clean_input == 0)
		ft_putstr("This minishell does not support multiline commands\n");
	else
		ft_putstr(clean_input);
	ft_putchar('\n');
	return (0);
	if (!*clean_input)
		return (0);
	if (!ft_strcmp(clean_input, "echo"))
		handle_echo(&clean_input);
	else if (!ft_strcmp(clean_input, "pwd"))
		handle_pwd();
	else
		write(1, "try again\n", 10);
	return (0);
}