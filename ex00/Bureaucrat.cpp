/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/03 05:37:36 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ----- canonical form ----- */
Bureaucrat::Bureaucrat() : name("default_name"), grade(150)
{
	if (DEBUG_FLAG)
		log("Bureaucrat-> Default constructor called");
}

Bureaucrat::Bureaucrat(const std::string &given_name, int given_grade)
	: name(given_name), grade(given_grade)
{
	if (DEBUG_FLAG)
		log("Bureaucrat-> parameter constructor called");
	if (given_grade < 1)
		throw(GradeTooHighException());
	if (given_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	if (DEBUG_FLAG)
		log("Bureaucrat-> Copy constructor called");
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	if (DEBUG_FLAG)
		log("Bureaucrat-> Default destructor called");
}



/* ----- methods ----- */
std::string Bureaucrat::getName()
{
	return name;
}

int Bureaucrat::getGrade()
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if ((grade--) < 1)
		throw(GradeTooHighException());
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if ((grade++) > 150)
		throw(GradeTooLowException());
	grade++;
}

void Bureaucrat::printStats()
{
	log("printing stats...");
	std::cout << "my name is " << name << std::endl;
	std::cout << "my grade is "<< grade << std::endl;
}



/* ----- exceptions ----- */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("DEBUG: vishhh nota ta mto alta");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("DEBUG: vish nota mto baixa");
}



/* ----- aux functions and operator overloads ----- */
void log(std::string message)
{
	std::cout << message << std::endl;
}

std::ostream &operator<<(std::ostream &out_stream, Bureaucrat &x)
{
	out_stream << x.getName() << ", bureaucrat grade " << x.getGrade();
	return (out_stream);
}
