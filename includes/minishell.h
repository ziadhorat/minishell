/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:36:09 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/23 11:36:31 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PATH_MAX 4096
# define NOT_SPECIAL(c) ((c != '$' && c != ':') ? 1 : 0)
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

char			**g_env;
char			*get_env(char *a);
void			handle_input(char **a);
void			initialize_env(char *a[]);
void			display_prompt(void);
int				exec_command(char **a);
int				env_len(char *a[]);
int				env_b(void);
int				cd_b(char **a, int b);
int				set_env_var(char *a, char *b);
int				setenv_b(char **a);
int				unsetenv_b(char **a);
int				echo_b(char **a);
int				exec_path(char *a, char **b);
char			*in_path(char **a);
int				is_executable(char **a, char *b, struct stat c);
char			*get_handled_path(void);
int				change_dir(char *a, int b);
char			**argsplit(char *str);

#endif
