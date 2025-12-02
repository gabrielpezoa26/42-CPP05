/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/02 16:41:53 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ----- canonical form -----*/
Bureaucrat::Bureaucrat() : name("default_name"), grade(150)
{
	log("Bureaucrat-> Default constructor called");
}

Bureaucrat::Bureaucrat(const std::string &given_name, unsigned int given_grade)
	: name(given_name), grade(given_grade)
{
	log("Bureaucrat-> parameter constructor called");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
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
	log("Bureaucrat-> Default destructor called");
}

void log(std::string message)
{
	std::cout << message << std::endl;
}

/* ----- methods -----*/


