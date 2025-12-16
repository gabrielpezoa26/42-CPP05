/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:06 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/16 18:52:34 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat a("Bob", 1);
	PresidentialPardonForm b("target");

	a.signForm(a, b);
	a.executeForm(b);
	

	log("compiled!");
	return (0);
}
