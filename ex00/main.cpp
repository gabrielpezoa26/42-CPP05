/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/04 19:42:40 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void validBureaucrat()
{
	log("creating valid bureaucrat");
	try
	{
		Bureaucrat a("Walter White", 3);
		
		a.printStats();
		a.incrementGrade();
		a.printStats();
		log("\n\n\n");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void invalidBureaucrat()
{
	log(" now trying to create a invalid bureaucrat");
	try
	{
		Bureaucrat b("Jesse pinkman", 151);
		log("\n\n\n");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	log("\n\n\n");
}

void invalidGradeChange()
{
	try
	{
		Bureaucrat c("Hank Schrader", 3);
		c.printStats();
		log("wrongly incrementing grade...");
		for(int i = 0; i < 5; i++)
		{
			c.incrementGrade();
			c.printGrade();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



	log(" now wrongly decrementing grade...");
	try
	{
		Bureaucrat c("Hank Schrader", 148);
		c.printStats();
		for(int i = 0; i < 5; i++)
		{
			c.decrementGrade();
			c.printGrade();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main()
{
	validBureaucrat();
	invalidBureaucrat();

	invalidGradeChange();


	return (0);
}