/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:57:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 15:57:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include "structs.h"
# include "libft.h"
# include "math.h"

t_complex	*new_complex(double real, double imag);
void		set_complex(t_complex *complex, double real, double imag);
double		complex_magnitude(t_complex number);

#endif
