/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:46:17 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/26 11:35:48 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	s = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s)
		return (NULL);
	res = s;
	while (*s1)
		*s++ = *s1++;
	*s = ' ';
	s++;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (res);
}
