/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:02 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/03 06:02:58 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define DEBUG_FLAG 0

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
		void printStats();



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
std::ostream &operator<<(std::ostream &out_stream, Bureaucrat &x);

#endif