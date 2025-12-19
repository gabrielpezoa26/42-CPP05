NAME = Intern
OBJECTS = objects/main.o objects/Bureaucrat.o objects/AForm.o objects/ShrubberyCreationForm.o objects/PresidentialPardonForm.o \
	objects/RobotomyRequestForm.o objects/Intern.o
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = objects

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

objects/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o objects/main.o

objects/Bureaucrat.o: Bureaucrat.cpp
	$(CC) $(CFLAGS) -c Bureaucrat.cpp -o objects/Bureaucrat.o

objects/AForm.o: AForm.cpp
	$(CC) $(CFLAGS) -c AForm.cpp -o objects/AForm.o

objects/ShrubberyCreationForm.o: ShrubberyCreationForm.cpp
	$(CC) $(CFLAGS) -c ShrubberyCreationForm.cpp -o objects/ShrubberyCreationForm.o

objects/PresidentialPardonForm.o: PresidentialPardonForm.cpp
	$(CC) $(CFLAGS) -c PresidentialPardonForm.cpp -o objects/PresidentialPardonForm.o

objects/RobotomyRequestForm.o: RobotomyRequestForm.cpp
	$(CC) $(CFLAGS) -c RobotomyRequestForm.cpp -o objects/RobotomyRequestForm.o

objects/Intern.o: Intern.cpp
	$(CC) $(CFLAGS) -c Intern.cpp -o objects/Intern.o


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all