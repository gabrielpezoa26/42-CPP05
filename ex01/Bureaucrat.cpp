/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/15 10:18:53 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ----- canonical form ----- */
Bureaucrat::Bureaucrat() : name("default_name"), grade(150)
{
	if (DEBUG_MODE)
		printDebug("Bureaucrat-> Default constructor called");
}

Bureaucrat::Bureaucrat(const std::string &given_name, int given_grade)
	: name(given_name), grade(given_grade)
{
	if (DEBUG_MODE)
		printDebug("Bureaucrat-> parameter constructor called");
	if (given_grade < 1)
		throw(GradeTooHighException());
	if (given_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	if (DEBUG_MODE)
		printDebug("Bureaucrat-> Copy constructor called");
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
		printDebug("Bureaucrat-> Default destructor called");
}



/* ----- methods ----- */
std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (DEBUG_MODE)
		printDebug("incrementGrade() called");
	if ((grade - 1) < 1)
		throw(GradeTooHighException());
	grade--;
	logColor("grade incremented!", YELLOW);
}

void Bureaucrat::decrementGrade()
{
	if (DEBUG_MODE)
		printDebug("decrementGrade() called");
	if ((grade + 1) > 150)
		throw(GradeTooLowException());
	grade++;
	logColor("grade decremented!", YELLOW);
}

void Bureaucrat::printGrade()
{
	std::cout << "my grade is "<< grade << std::endl;
}

void Bureaucrat::signForm(Bureaucrat &x, Form &y)
{
	try
	{
		y.beSigned(x);
		std::cout << GREEN << x.getName() << " signed " << y.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << x.getName() << " couldn’t sign " << y.getName() << " because " << e.what() << std::endl;
	}
	
}



/* ----- exceptions ----- */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat-> Exception caught: Grade too high! (Grade must be between 1 and 150)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat-> Exception caught: Grade too low! (Grade must be between 1 and 150)");
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

void printDebug(std::string debug_message)
{
	std::cout << PURPLE << debug_message << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out_stream, const Bureaucrat &x)
{
	if (DEBUG_MODE)
		printDebug("Bureaucrat-> insertion (<<) overload operator called");
	out_stream << x.getName() << ", bureaucrat grade " << x.getGrade();
	return (out_stream);
}
