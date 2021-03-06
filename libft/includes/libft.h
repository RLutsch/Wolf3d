/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:46:20 by rlutsch           #+#    #+#             */
/*   Updated: 2016/12/01 15:50:14 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ft_fc_mem.h>
# include <ft_fc_str.h>
# include <ft_fc_tests.h>
# include <ft_fc_print.h>
# include <ft_fc_conversion.h>
# include <get_next_line.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_match(char *s1, char *s2);
int					ft_nmatch(char *s1, char *s2);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
char				*ft_strmerge(char *a, char *b);
char				**ft_strsplit(char const *s, char c);
int					*ft_strsplittoint(char const *s, char c);
#endif
