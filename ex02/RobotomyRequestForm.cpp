/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:29:20 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/16 19:38:23 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ----- canonical form ----- */
RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45, "default")
{
	if (DEBUG_MODE)
		printDebug("Robotomy-> Default constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &form_target)
: AForm("RobotomyRequestForm", 72, 45, form_target)
{
	if (DEBUG_MODE)
		printDebug("Robotomy-> Parameter constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other)
{
	if (DEBUG_MODE)
		printDebug("Robotomy-> Copy constructor called");
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
		printDebug("Robotomy-> Default destructor called");
}

void  RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (DEBUG_MODE)
		printDebug("Robotomy-> execute() called");
	if (getIsSigned() == false)
		throw(FormNotSignedException());
	if (executor.getGrade() > 45)
		throw(GradeTooLowException());
	robotomy(getTarget());
}


/* ----- methods ----- */
void RobotomyRequestForm::robotomy(std::string form_target) const
{
	int random_number = rand() % 11;
	if (DEBUG_MODE)
	{
		std::cout << form_target << std::endl;  //tirar dps
		printDebug("Robotomy-> robotomy() called");
	}

	if (random_number >= 5)
		log("deu bom");
	else if (random_number > 5)
		log ("deu ruim");
}


