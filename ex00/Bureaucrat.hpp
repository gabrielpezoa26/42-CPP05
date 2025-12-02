/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:02 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/02 16:41:40 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;


	public:
		/* ----- canonical form -----*/
		Bureaucrat();
		Bureaucrat(const std::string &given_name, unsigned int given_grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		/* ----- methods -----*/
		// getName();
		// getGrade();
		// incrementGrade();
		// decrementGrade();
		

};


void	log(std::string message);

#endif