/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:35:31 by tpons             #+#    #+#             */
/*   Updated: 2021/01/30 16:58:45 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		check_export(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int		print_export(char **env)
{
	int	i;
	int j;
	int	equal;

	i = -1;
	while (env[++i])
	{
		equal = 1;
		j = 0;
		ft_putstr("declare -x ");
		while (env[i][j])
		{
			if (env[i][j] == '\\' || env[i][j] == '$' ||
			env[i][j] == '\"')
				write(1, "\\", 1);
			write(1, &env[i][j], 1);
			if (env[i][j] == '=' && equal-- == 1)
				write(1, "\"", 1);
			j++;
		}
		if (equal != 1)
			write(1, "\"", 1);
		write(1, "\n", 1);
	}
	return (1);
}
