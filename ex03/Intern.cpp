/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:50:00 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/19 12:31:42 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ----- canonical form ----- */
Intern::Intern()
{
	if (DEBUG_MODE)
		printDebug("Intern-> Constructor called");
}

Intern::Intern(const Intern &src)
{
	if (DEBUG_MODE)
		printDebug("Intern-> Copy constructor called");
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
	if (DEBUG_MODE)
		printDebug("Intern-> Destructor called");
}

/* ----- methods ----- */
AForm *Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string form_names[] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
	};
	AForm *(Intern::*function_pointers[])(std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == form_names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*function_pointers[i])(target);
		}
	}
	std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
	throw Intern::FormNotFoundException();
}

/* ----- exceptions ----- */
const char *Intern::FormNotFoundException::what() const throw()
{
	return "Intern error: Form name not found.";
}