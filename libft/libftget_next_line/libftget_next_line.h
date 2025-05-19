/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftget_next_line.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:44:03 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/19 12:49:49 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTGET_NEXT_LINE_H
# define LIBFTGET_NEXT_LINE_H

# include "../libft.h"
# include <fcntl.h>

//BUFFER_SIZE to read files when using get_next_line function
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

#endif