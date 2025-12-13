/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:02 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/13 11:23:40 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

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



};



#endif
