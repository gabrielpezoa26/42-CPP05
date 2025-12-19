/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:50:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/19 12:06:47 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm   *makePresidential(std::string target);
		AForm   *makeRobotomy(std::string target);
		AForm   *makeShrubbery(std::string target);



	public:
		/* ----- canonical form ----- */
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();



		/* ----- methods ----- */
		AForm   *makeForm(std::string formName, std::string target);



	/* ----- exceptions ----- */
	class FormNotFoundException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif