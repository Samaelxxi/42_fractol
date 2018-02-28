/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:57:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 15:57:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	*new_complex(double real, double imag)
{
	t_complex	*complex;

	complex = malloc(sizeof(t_complex));
	complex->real = real;
	complex->imag = imag;
	return (complex);
}

void		set_complex(t_complex *complex, double real, double imag)
{
	complex->real = real;
	complex->imag = imag;
}

double		complex_magnitude(t_complex number)
{
	return (sqrt(number.real * number.real + number.imag * number.imag));
}
