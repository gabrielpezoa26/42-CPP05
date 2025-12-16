/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:06 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/16 17:41:12 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat a("Bob", 10);
	PresidentialPardonForm b("target");

	a.executeForm(b);
	

	log("compiled!");
	return (0);
}
