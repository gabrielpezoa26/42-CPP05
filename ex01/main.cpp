/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/13 20:59:59 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void testValidBureaucrat();
static void testInvalidBureaucrat();
static void testInvalidGradeChange();
// static void testFormSigning();

int main()
{
	testValidBureaucrat();
	testInvalidBureaucrat();
	testInvalidGradeChange();
	// testFormSigning();


	return (0);
}

static void testValidBureaucrat()
{
	logColor("creating valid bureaucrat", GREEN);
	try
	{
		Bureaucrat a("Walter White", 3);
		
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		log("\n\n\n");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void testInvalidBureaucrat()
{
	logColor(" now trying to create a invalid bureaucrat", RED);
	try
	{
		Bureaucrat b("Hank Schrader", 151);
		log("\n\n\n");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	log("\n\n\n");
}

static void testInvalidGradeChange()
{
	logColor(" and finally, testing grade incrementing/decrementing limits", BLUE);
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
		Bureaucrat c("Gus Fring", 148);
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

// static void testFormSigning()
// {
// 	log("\n now")
// }