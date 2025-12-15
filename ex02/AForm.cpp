/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:11 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/14 22:16:03 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ----- canonical form ----- */
AForm::AForm() 
 : _name("standard_form"), _is_signed(false), _required_grade_to_sign(150), _required_grade_to_exec(150)
{
	if (DEBUG_MODE)
		printDebug("AForm-> Default constructor called");
}

AForm::AForm(const std::string& name, int required_grade_to_sign, int required_grade_to_exec, const std::string &target)
 : _name(name), _is_signed(false), _required_grade_to_sign(required_grade_to_sign), _required_grade_to_exec(required_grade_to_exec), _target(target)
{
	if (DEBUG_MODE)
		printDebug("AForm-> Parameter constructor called");
	if (required_grade_to_sign < 1 || required_grade_to_exec < 1)
		throw(GradeTooHighException());
	if (required_grade_to_sign > 150 || required_grade_to_exec > 150)
		throw(GradeTooLowException());
	
	
}

AForm::AForm(const AForm& other)
 : _name(other._name),
 _is_signed(other._is_signed),
 _required_grade_to_sign(other._required_grade_to_sign),
 _required_grade_to_exec(other._required_grade_to_exec)
{
	if (DEBUG_MODE)
		printDebug("AForm-> Copy constructor called");
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

AForm::~AForm()
{
	if (DEBUG_MODE)
		printDebug("AForm-> Default destructor called");
}



/* ----- getters ----- */
std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _is_signed;
}

int AForm::getRequiredGradeToSign() const
{
	return _required_grade_to_sign;
}

int AForm::getRequiredGradeToExec() const
{
	return _required_grade_to_exec;
}



/* ----- exceptions ----- */
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm-> Exception caught: Grade too high! (Grade must be between 1 and 150)");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm-> Exception caught: Grade too low! (Grade must be between 1 and 150)");
}



/* ----- methods ----- */
void AForm::beSigned(const Bureaucrat &x)
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

std::ostream &operator<<(std::ostream &out_stream, const AForm &x)
{
	if (DEBUG_MODE)
		printDebug("AForm-> insertion (<<) overload operator called");

	out_stream << "the form name is: " << x.getName() << std::endl;
	out_stream << "is it signed? " << x.getIsSigned() << std::endl;
	out_stream << "the sign grade is: " << x.getRequiredGradeToSign() << std::endl;
	out_stream << "the exec grade is: " << x.getRequiredGradeToExec() << std::endl;
	return (out_stream);
}