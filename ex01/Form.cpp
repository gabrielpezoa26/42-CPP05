/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:42:50 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/14 14:48:21 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ----- canonical form ----- */
Form::Form() 
 : _name("standard_form"), _is_signed(false), _required_grade_to_sign(150), _required_grade_to_exec(150)
{
	if (DEBUG_MODE)
		printDebug("Default constructor called");
}

Form::Form(const std::string& name, int required_grade_to_sign, int required_grade_to_exec)
 : _name(name), _is_signed(false), _required_grade_to_sign(required_grade_to_sign), _required_grade_to_exec(required_grade_to_exec)
{
	if (DEBUG_MODE)
		printDebug("Form-> Parameter constructor called");
	if (required_grade_to_sign < 1 || required_grade_to_exec < 1)
		throw(GradeTooHighException());
	if (required_grade_to_sign > 150 || required_grade_to_exec > 150)
		throw(GradeTooLowException());
	
	
}

Form::Form(const Form& other)
 : _name(other._name),
 _is_signed(other._is_signed),
 _required_grade_to_sign(other._required_grade_to_sign),
 _required_grade_to_exec(other._required_grade_to_exec)
{
	if (DEBUG_MODE)
		printDebug("Form-> Copy constructor called");
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

Form::~Form()
{
	if (DEBUG_MODE)
		printDebug("Form-> Default destructor called");
}



/* ----- getters ----- */
std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _is_signed;
}

int Form::getRequiredGradeToSign() const
{
	return _required_grade_to_sign;
}

int Form::getRequiredGradeToExec() const
{
	return _required_grade_to_exec;
}



/* ----- exceptions ----- */
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form-> Exception caught: Grade too high! (Grade must be between 1 and 150)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form-> Exception caught: Grade too low! (Grade must be between 1 and 150)");
}



/* ----- methods ----- */
void Form::beSigned(const Bureaucrat &x)
{
	if (DEBUG_MODE)
		printDebug("beSigned() called");
	if (x.getGrade() <= _required_grade_to_sign)
	{
		_is_signed = true;
	}
	else if (x.getGrade() > _required_grade_to_sign)
	{
		throw(GradeTooLowException());
	}
}

void Form::printFormStats()
{
	std::cout << _name << std::endl;
	std::cout << _is_signed << std::endl;
	std::cout << _required_grade_to_sign << std::endl;
	std::cout << _required_grade_to_exec << std::endl;
}

std::ostream &operator<<(std::ostream &out_stream, const Form &x)
{
	if (DEBUG_MODE)
		printDebug("Form-> insertion (<<) overload operator called");


	out_stream << "form name is: " << x.getName() << std::endl;
	out_stream << "form signed is: " << x.getIsSigned() << std::endl;
	out_stream << "form sign grade is: " << x.getRequiredGradeToSign() << std::endl;
	out_stream << "form exec grade is: " << x.getRequiredGradeToExec() << std::endl;
	return (out_stream);
}
