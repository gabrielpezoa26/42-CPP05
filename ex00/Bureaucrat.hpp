/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:02 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/04 23:42:20 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define DEBUG_MODE 0

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
		std::string getName();
		int getGrade();
		void incrementGrade();
		void decrementGrade();
		void printFullStats();
		void printGrade();



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
std::ostream &operator<<(std::ostream &out_stream, Bureaucrat &x);

#endif