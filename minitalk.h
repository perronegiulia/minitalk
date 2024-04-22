/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:29:24 by gmaia-pe          #+#    #+#             */
/*   Updated: 2024/04/22 19:57:57 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_strjoinc(char *str, char c);
void	ft_putnbr(int num);

#endif