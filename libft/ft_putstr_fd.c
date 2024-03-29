/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquince <jquince@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:04:22 by jquince           #+#    #+#             */
/*   Updated: 2019/10/10 18:32:58 by jquince          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}
