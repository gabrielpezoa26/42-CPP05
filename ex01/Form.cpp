/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:42:50 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/09 12:16:29 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
	if (DEBUG_MODE)
		printDebug("Form-> Default constructor called");
}

Form::Form(const Form& other)
 : name(other.name),
 is_signed(other.is_signed),
 required_grade_to_sign(other.required_grade_to_sign),
 required_grade_to_exec(other.required_grade_to_exec)
{
	if (DEBUG_MODE)
		printDebug("Form-> Copy constructor called");
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
		this->is_signed = other.required_grade_to_sign;
		this->is_signed = other.required_grade_to_exec;
	}
	return (*this);
}

Form::~Form()
{
	if (DEBUG_MODE)
		printDebug("Form-> Default destructor called");
}