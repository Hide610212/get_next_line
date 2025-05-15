/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuto <hmuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:01:19 by hmuto             #+#    #+#             */
/*   Updated: 2025/05/15 18:00:02 by hmuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

// Calculate length of string
size_t ft_strlen(const char *s)
{
    size_t len = 0;
    if (!s)
        return 0;
    while (s[len])
        len++;
    return len;
}

// Locate first occurrence of char c in string s
char *ft_strchr(const char *s, int c)
{
    if (!s)
        return NULL;
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return NULL;
}

char *ft_strdup(const char *s)
{
    size_t len;
    char *dup;
    size_t i;

    len = ft_strlen(s);
    dup = malloc(len + 1);

    if (dup == NULL)
        return NULL;

    i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

// Extract substring of length len from s starting at index 0
char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t slen;
    size_t alloc_len;
    size_t i;
    char *sub;

    slen = ft_strlen(s);
    if (start >= slen)
        return NULL;
    alloc_len = slen - start;
    if (alloc_len > len)
        alloc_len = len;

    sub = malloc(alloc_len + 1);
    if (!sub)
        return NULL;

    i = 0;
    while (i < alloc_len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return sub;
}

char *ft_strjoin_and_free(char *s1, const char *s2)
{
    size_t len1;
    size_t len2;
    size_t i;
    size_t j;
    char *joined;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    joined = malloc(len1 + len2 + 1);
    if (!joined)
        return NULL;
    i = 0;
    while (i < len1)
    {
        joined[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < len2)
    {
        joined[i + j] = s2[j];
        j++;
    }
    joined[len1 + len2] = '\0';
    free(s1);
    return joined;
}
