/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/14 17:08:45 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void testValidBureaucrat();
static void testInvalidBureaucrat();
static void testInvalidGradeChange();
static void testFormCreation();
static void testFormSigning();

int main()
{
	if (FULL_TEST)
	{
		testValidBureaucrat();
		testInvalidBureaucrat();
		testInvalidGradeChange();
	}
	testFormCreation();
	testFormSigning();

	log("\nprogram finished :))");
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

static void testFormCreation()
{
	try
	{
		log("Testing form creation");
		log("creating a valid form...");
		Form validForm("valid_form", 10, 20);
		std::cout << validForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		log("attempting to create a invalid form...");
		Form invalidForm("invalid_form", 100, 151);
		std::cout << invalidForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		log("\nattempting to create a invalid form again...");
		Form invalidForm("invalid_form", 100, -1);
		std::cout << invalidForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


static void testFormSigning()
{
	try
	{
		logColor("\n\n now let's make a bureaucrat sign something", YELLOW);
		Bureaucrat a("bob", 60);
		Form b("form_one", 100, 50);

		std::cout << b << std::endl;

		a.signForm(a, b);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		logColor("Now attempting to sign a form....", RED);
		Bureaucrat x("Johnny", 101);
		Form y("form_two", 100, 100);

		std::cout << y << std::endl;
		x.signForm(x, y);
		std::cout << y << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
