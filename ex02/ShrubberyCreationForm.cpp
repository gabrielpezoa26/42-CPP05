/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:04:35 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/16 18:59:48 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ----- canonical form ----- */
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137, "default")
{
	if (DEBUG_MODE)
		printDebug("Shrubbery-> Default constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &form_target)
: AForm("ShrubberyCreationForm", 145, 137, form_target)
{
	if (DEBUG_MODE)
		printDebug("Shrubbery-> Parameter constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other)
{
	if (DEBUG_MODE)
		printDebug("Shrubbery-> Copy constructor called");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		ShrubberyCreationForm::AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DEBUG_MODE)
		printDebug("Shrubbery-> Default destructor called");
}

void  ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (DEBUG_MODE)
		printDebug("Shrubbery-> execute() called");
	if (getIsSigned() == false)
		throw(FormNotSignedException());
	if (executor.getGrade() > 137)
		throw(GradeTooLowException());
	createTrees(getTarget());
	std::cout << executor << " executed " << getName() << std::endl;
}

/* ----- methods ----- */
void ShrubberyCreationForm::createTrees(std::string form_target) const
{
	if (DEBUG_MODE)
	{
		std::cout << form_target << std::endl;  // tirar dps
		printDebug("Shrubbery-> CreateTrees() called");
	}
}
