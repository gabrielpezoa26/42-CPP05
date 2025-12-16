/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:29:20 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/16 17:38:36 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ----- canonical form ----- */
RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45, "default")
{
	if (DEBUG_MODE)
		printDebug("Presidential-> Default constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &form_target)
: AForm("RobotomyRequestForm", 72, 45, form_target)
{
	if (DEBUG_MODE)
		printDebug("Presidential-> Parameter constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other)
{
	if (DEBUG_MODE)
		printDebug("Presidential-> Copy constructor called");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		RobotomyRequestForm::AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (DEBUG_MODE)
		printDebug("Presidential-> Default destructor called");
}

void  RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw(FormNotSignedException());
	if (executor.getGrade() > 45)
		throw(GradeTooLowException());
	robotomy(getTarget());
	std::cout << executor << " executed " << getName() << std::endl;
}


/* ----- methods ----- */
void RobotomyRequestForm::robotomy(std::string form_target) const
{
	if (DEBUG_MODE)
	{
		std::cout << form_target << std::endl;  //tirar dps
		printDebug("Robotomy-> pardon() called");
	}
}


