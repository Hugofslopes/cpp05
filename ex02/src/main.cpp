/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:57:11 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 10:46:29 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
    {
        try{
            Bureaucrat b1(6, "Alice");
            PresidentialPardonForm  f1("TopSecret");
            std::cout << std::endl;

            b1.signForm(f1);  
            b1.executeForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    {
        try{
            Bureaucrat b1(5, "Alice");
            PresidentialPardonForm  f1("TopSecret");
            std::cout << std::endl;

            b1.signForm(f1);  
            b1.executeForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    {
        Bureaucrat b1(146, "Alice");
        ShrubberyCreationForm  f1("My Home");
        std::cout << std::endl;
        try{
            b1.signForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << std::endl;
        b1.operator--();
        std::cout << b1 << std::endl;
        b1.signForm(f1);
        try{
            b1.executeForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        for (int  i = 0; i < 8; i++)
            b1.operator--();
        std::cout << b1 <<std::endl;
        b1.executeForm(f1);
    }
    std::cout << std::endl << std::endl;
    {
        Bureaucrat b1(45, "Alice");
        RobotomyRequestForm  f1("My Home");
        std::cout << std::endl;
        try{
            b1.signForm(f1);
            std::cout << std::endl;
            b1.executeForm(f1);
            std::cout << std::endl;
            b1.executeForm(f1);
            std::cout << std::endl;
            b1.executeForm(f1);
            std::cout << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
}
