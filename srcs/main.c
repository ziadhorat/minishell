/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:42:00 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/23 13:56:43 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		ft_headerprint(void)
{
	int		fd;
	char	*line;

	system("@cls||clear");
	ft_putstr("\033[1;32m");
	fd = open("includes/ascii_art/header.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_putstr("\033[0m");
}

static int		exec_com(char **coms)
{
	int		i;
	int		ret;
	char	**com;

	i = 0;
	while (coms[i])
	{
		com = argsplit(ft_strdup(coms[i]));
		handle_input(com);
		ret = exec_command(com);
		ft_freestrarray(com);
		ft_freestrarray(coms);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (0);
}

static void		sh_level(int ac, char *av[])
{
	char	*level;

	(void)ac;
	(void)av;
	level = ft_itoa(ft_atoi(get_env("SHLVL")) + 1);
	set_env_var("SHLVL", level);
	free(level);
}

char	*ft_linehandler(char *str)
{
	char	*str2;
	char	*tmp;
	char	*ptr;

	ptr = str;
	while ((ptr = ft_strchr(ptr, '"')) != NULL)
	{
		++ptr;
		if ((ptr = ft_strchr(ptr, '"')) == NULL)
		{
			str2 = readline("\033[1;32mPLEASE END DQUOTE $>\033[0m");
			tmp = ft_strjoin(str, "\n");
			ft_strdel(&str);
			str = ft_strjoin(tmp, str2);
			ft_strdel(&str2);
			ft_strdel(&tmp);
			ptr = str;
		}
		else
			ptr++;
	}
	return (str);
}

int				main(int ac, char *av[], char *env[])
{
	char	*line;
	char	*prompt;
	char	**coms;
	char	*str;

	initialize_env(env);
	sh_level(ac, av);
	ft_headerprint();
	while (1)
	{
		prompt = get_handled_path();
		str = readline(prompt);
		line = ft_linehandler(str);
		ft_strdel(&prompt);
		add_history(line);
		coms = ft_strsplit(line, ';');
		free(line);
		if (exec_com(coms) == -1)
			break ;
	}
	ft_freestrarray(g_env);
	return (0);
}
