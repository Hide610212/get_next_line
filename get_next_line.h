/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuto <hmuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:02:13 by hmuto             #+#    #+#             */
/*   Updated: 2025/05/15 14:02:14 by hmuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>  // malloc, free, size_t
# include <unistd.h>  // read()

// 関数プロトタイプ
char    *get_next_line(int fd);
char    *extract_line(char *saved);
char    *update_saved(char *saved);
char    *read_and_save(int fd, char *saved);

// ヘルパー関数
char    *ft_strjoin_and_free(char *s1, const char *s2);
char    *ft_strdup(const char *s1);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);

#endif