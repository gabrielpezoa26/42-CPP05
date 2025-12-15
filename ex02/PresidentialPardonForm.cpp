/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:59:11 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/14 23:43:50 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ----- canonical form ----- */
PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5, "default")
{
	if (DEBUG_MODE)
		printDebug("Presidential-> Default constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &form_target)
: AForm("PresidentialPardonForm", 25, 5, form_target)
{
	if (DEBUG_MODE)
		printDebug("Presidential-> Parameter constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other)
{
	if (DEBUG_MODE)
		printDebug("Presidential-> Copy constructor called");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		PresidentialPardonForm::AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (DEBUG_MODE)
		printDebug("Presidential-> Default destructor called");
}



/* ----- methods ----- */
void PresidentialPardonForm::pardon(const std::string &form_target)
{
	if (DEBUG_MODE)
	{
		std::cout << form_target << std::endl;  //tirar dps
		printDebug("Presidential-> pardon() called");
	}
}
