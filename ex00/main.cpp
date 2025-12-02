/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/02 19:51:14 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Jack sparrow", 3);
	Bureaucrat b;
	a.printStats();
	b.printStats();
	// Bureaucrat b("jack sparrow", -3);

	
	log("compileddd");
	return (0);
}