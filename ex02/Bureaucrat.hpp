/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:23 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/17 14:31:26 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define DEBUG_MODE false
#define FULL_TEST false


class Bureaucrat
{
	private:
		const std::string name;
		int grade;



	public:
		/* ----- canonical form ----- */
		Bureaucrat();
		Bureaucrat(const std::string &given_name, int given_grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();


		/* ----- methods ----- */
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void printGrade();
		void signForm(Bureaucrat &x, AForm &y);
		void executeForm(AForm const &form) const;

		

	/* ----- exceptions ----- */
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

void	log(std::string message);
void	logColor(std::string message, std::string color);
void	printDebug(std::string debug_message);
std::ostream &operator<<(std::ostream &out_stream, const Bureaucrat &x);

#endif