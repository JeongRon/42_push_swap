/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:57:38 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/28 19:25:20 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// bonus_checker.c
int			check_sorted(t_stack **a);
int			ft_strcmp(char *s1, char *s2);
void		checker_res(int flag, t_stack **a, t_stack **b);
int			check_one_command(char *buff, t_stack **a, t_stack **b);
void		read_all_command(t_stack **a, t_stack **b);
int			main(int ac, char **av);

// bonus_gnl_util.c
char		*ft_strdup(char *src);
void		free_all(char *a, char *b);
char		*ft_strjoin(char *buff, char *tmp, int tmp_len);

#endif
