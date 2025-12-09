/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:43:02 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/09 12:25:44 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		int required_grade_to_sign;
		int required_grade_to_exec;



	public:
		/* ----- canonical form ----- */
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();



};



#endif
