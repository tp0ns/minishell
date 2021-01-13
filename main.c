/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/13 13:49:20 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	ac = 0;
	av = NULL;
	data = init_data(env);
	while (1)
	{
		ft_putstr("minishell> ");
		get_next_line(0, &data.user_input);
		parser(data);
	}
	return (0);
}
