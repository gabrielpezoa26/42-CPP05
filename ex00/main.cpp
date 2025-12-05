/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/04 23:45:43 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testValidBureaucrat()
{
	logColor("creating valid bureaucrat", GREEN);
	try
	{
		Bureaucrat a("Walter White", 3);
		
		// a.printFullStats();
		std::cout << a << std::endl;
		a.incrementGrade();
		// a.printFullStats();
		std::cout << a << std::endl;
		log("\n\n\n");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testInvalidBureaucrat()
{
	logColor(" now trying to create a invalid bureaucrat", RED);
	try
	{
		Bureaucrat b("Gus Fring", 151);
		log("\n\n\n");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	log("\n\n\n");
}

void testInvalidGradeChange()
{
	logColor(" and finally, testing grade incrementing/decrementing", BLUE);
	try
	{
		Bureaucrat c("Jesse Pinkman", 3);
		log("Bureaucrat created!");
		std::cout << c << std::endl;
		log("incrementing grade...");
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



	log(" \nnow decrementing grade...");
	try
	{
		Bureaucrat c("Hank Schrader", 148);
		log("Bureaucrat created!");
		std::cout << c << std::endl;
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
	testValidBureaucrat();
	testInvalidBureaucrat();

	testInvalidGradeChange();
	return (0);
}