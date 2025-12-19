/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:06 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/19 11:50:53 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void testValidBureaucrat();
static void testInvalidBureaucrat();
static void testInvalidGradeChange();
static void testShrubbery();
static void testRobotomy();
static void testPresidentialPardon();

int main()
{
	Bureaucrat a("Bob", 1);
	ShrubberyCreationForm d("house");

	if (REGRESSION_TEST)
	{
		logColor("------- Testing previous exercise methods -------", YELLOW);
		testValidBureaucrat();
		testInvalidBureaucrat();
		testInvalidGradeChange();
	}
	logColor("\n------- Now testing ex02 specific methods -------", YELLOW);
	testShrubbery();
	testRobotomy();
	testPresidentialPardon();
	
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

static void testShrubbery()
{
	ShrubberyCreationForm a("house");
	ShrubberyCreationForm x("castle");
	Bureaucrat b("high_grade_bureaucrat", 1);
	Bureaucrat c ("low_grade_bureaucrat", 150);

	logColor("testing sign and executing Shrubbery form", BLUE);
	try
	{
		b.signForm(b, a);
		b.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	logColor("\nnow attempting to sign it with a low grade bureaucrat", RED);
	try
	{
		c.signForm(c, x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	logColor("\n now trying to execute a not signed form", RED);
	try
	{
		b.executeForm(x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void testRobotomy()
{
	RobotomyRequestForm a("bob");
	RobotomyRequestForm x("walter");
	Bureaucrat b("high_grade_bureaucrat", 1);
	Bureaucrat c ("low_grade_bureaucrat", 150);

	logColor("testing sign and executing Robotomy form", BLUE);
	try
	{
		b.signForm(b, a);
		b.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	logColor("\nnow attempting to sign it with a low grade bureaucrat", RED);
	try
	{
		c.signForm(c, x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	logColor("\n now trying to execute a not signed form", RED);
	try
	{
		b.executeForm(x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void testPresidentialPardon()
{
	PresidentialPardonForm a("Joe");
	PresidentialPardonForm x("walter");
	Bureaucrat b("high_grade_bureaucrat", 1);
	Bureaucrat c ("low_grade_bureaucrat", 150);

	logColor("testing sign and executing Presidiential Pardon form", BLUE);
	try
	{
		b.signForm(b, a);
		b.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	logColor("\nnow attempting to sign it with a low grade bureaucrat", RED);
	try
	{
		c.signForm(c, x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	logColor("\n now trying to execute a not signed form", RED);
	try
	{
		b.executeForm(x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
