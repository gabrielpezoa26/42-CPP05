/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:02 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/14 16:50:16 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;


class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _required_grade_to_sign;
		const int _required_grade_to_exec;


	public:
		/* ----- canonical form ----- */
		Form();
		Form(const std::string& name, int required_grade_to_sign, int required_grade_to_exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();


		/* ----- getters ----- */
		std::string	getName() const;
		bool		getIsSigned() const;
		int		getRequiredGradeToSign() const;
		int		getRequiredGradeToExec() const;


		/* ----- methods ----- */
		void beSigned(const Bureaucrat &x);




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

std::ostream &operator<<(std::ostream &out_stream, const Form &x);


#endif
