/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/04 19:38:07 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ----- canonical form ----- */
Bureaucrat::Bureaucrat() : name("default_name"), grade(150)
{
	if (DEBUG_MODE)
		logColor("Bureaucrat-> Default constructor called", YELLOW);
}

Bureaucrat::Bureaucrat(const std::string &given_name, int given_grade)
	: name(given_name), grade(given_grade)
{
	if (DEBUG_MODE)
		logColor("Bureaucrat-> parameter constructor called", YELLOW);
	if (given_grade < 1)
		throw(GradeTooHighException());
	if (given_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	if (DEBUG_MODE)
		logColor("Bureaucrat-> Copy constructor called", YELLOW);
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
	if (DEBUG_MODE)
		logColor("Bureaucrat-> Default destructor called", RED);
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
	logColor("grade incremented!", YELLOW);
	if ((grade - 1) < 1)
		throw(GradeTooHighException());
	grade--;
}

void Bureaucrat::decrementGrade()
{
	logColor("grade decremented!", YELLOW);
	if ((grade + 1) > 150)
		throw(GradeTooLowException());
	grade++;
}

void Bureaucrat::printStats()
{
	log("printing stats...");
	std::cout << "my name is " << name << std::endl;
	std::cout << "my grade is "<< grade << std::endl;
}

void Bureaucrat::printGrade()
{
	std::cout << "my grade is "<< grade << std::endl;
}


/* ----- exceptions ----- */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception caught: Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception caught: Grade too low!");
}



/* ----- aux functions and operator overloads ----- */
void log(std::string message)
{
	std::cout << message << std::endl;
}

void logColor(std::string message, std::string color)
{
	std::cout << color << message << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out_stream, Bureaucrat &x)
{
	out_stream << x.getName() << ", bureaucrat grade " << x.getGrade();
	return (out_stream);
}
