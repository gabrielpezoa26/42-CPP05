/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:06 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/16 21:15:26 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


int main()
{
	Bureaucrat a("Bob", 1);
	PresidentialPardonForm b("target1");
	RobotomyRequestForm c("robot");

	// a.signForm(a, b);
	// a.executeForm(b);
	
	a.signForm(a, c);
	a.executeForm(c);

	return (0);
}
