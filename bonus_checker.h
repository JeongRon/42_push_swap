/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:57:38 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 20:27:44 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

// bonus_checker.c
int			ft_strcmp(char *s1, char *s2);
int			run_one_command(char *str, t_stack **a, t_stack **b);
void		read_all_command(t_stack **a, t_stack **b);
int			main(int ac, char **av);

// bonus_gnl_*.c
char		*get_next_line(int fd);
char		*ft_strdup(char *src);
void		free_all(char *a, char *b);
int			ft_linelen(const char *s);
char		*ft_strjoin(char *join_buff, char *tmp, int tmp_len);

#endif
