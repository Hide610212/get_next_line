/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuto <hmuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:01:19 by hmuto             #+#    #+#             */
/*   Updated: 2025/05/19 15:00:32 by hmuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

// Calculate length of string
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

// Locate first occurrence of char c in string s
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// char *ft_strjoin_and_free(char *s1, const char *s2)
// {
//     size_t len1;
//     size_t len2;
//     size_t i;
//     size_t j;
//     char *joined;

//     len1 = ft_strlen(s1);
//     len2 = ft_strlen(s2);
//     joined = malloc(len1 + len2 + 1);
//     if (!joined)
//         return (NULL);
//     i = 0;
//     while (i < len1)
//     {
//         joined[i] = s1[i];
//         i++;
//     }
//     j = 0;
//     while (j < len2)
//     {
//         joined[i + j] = s2[j];
//         j++;
//     }
//     joined[len1 + len2] = '\0';
//     free(s1);
//     return (joined);
// }

// char *ft_strjoin_and_free(char *s1, const char *s2)
// {
//     size_t i;
//     size_t j;
//     char *joined;

//     joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//     if (!joined)
//         return (NULL);
//     i = 0;
//     while (i < ft_strlen(s1))
//     {
//         joined[i] = s1[i];
//         i++;
//     }
//     j = 0;
//     while (j < ft_strlen(s2))
//     {
//         joined[i + j] = s2[j];
//         j++;
//     }
//     joined[ft_strlen(s1) + ft_strlen(s2)] = '\0';
//     free(s1);
//     return (joined);
// }

char	*ft_strjoin_and_free(char *s1, const char *s2)
{
	char	*s3;
	char	*p3;
	char	*p1;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	s3 = malloc(sizeof(*s3) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	p3 = s3;
	p1 = s1;
	while (*p1)
		*p3++ = *p1++;
	while (*s2)
		*p3++ = *s2++;
	*p3 = 0;
	free(s1);
	return (s3);
}

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	len = ft_strlen(str);
	if (start >= len)
		return (ft_strdup(""));
	if (len - start < size)
		size = len - start;
	sub = malloc(sizeof(*sub) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}
