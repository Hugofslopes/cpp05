/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:57:11 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 11:22:15 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
    {
        Intern someRandomIntern;
        AForm* rrf  = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << std::endl;
        Bureaucrat b1(6, "Alice");
        std::cout << std::endl;
        b1.signForm(*rrf);
        std::cout << std::endl;
        b1.executeForm(*rrf);
        std::cout << std::endl;
        delete rrf;
    }
    std::cout << std::endl<< std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf  = someRandomIntern.makeForm("shrubbery creation", "Santa");
        std::cout << std::endl;
        Bureaucrat b1(6, "Elf");
        std::cout << std::endl;
        b1.signForm(*rrf);
        std::cout << std::endl;
        b1.executeForm(*rrf);
        std::cout << std::endl;
        delete rrf;
    }
    std::cout << std::endl<< std::endl;
    {
        Intern someRandomIntern;
        try{
        AForm* rrf  = someRandomIntern.makeForm("My precious", "Santa");
        std::cout << std::endl;
        Bureaucrat b1(6, "Elf");
        std::cout << std::endl;
        b1.signForm(*rrf);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
}
