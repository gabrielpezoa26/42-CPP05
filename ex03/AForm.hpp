/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:16 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/18 15:48:36 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;


class AForm
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _required_grade_to_sign;
		const int _required_grade_to_exec;
		const std::string _target;



	public:
		/* ----- canonical form ----- */
		AForm();
		AForm(const std::string& name, int required_grade_to_sign, int required_grade_to_exec, const std::string &target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();


		/* ----- getters ----- */
		std::string	getName() const;
		bool		getIsSigned() const;
		int		getRequiredGradeToSign() const;
		int		getRequiredGradeToExec() const;
		std::string	getTarget() const;


		/* ----- methods ----- */
		virtual void beSigned(const Bureaucrat &x);
		virtual void execute(Bureaucrat const &executor) const = 0;




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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};


};

std::ostream &operator<<(std::ostream &out_stream, const AForm &x);


#endif