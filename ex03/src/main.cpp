/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:57:11 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 15:28:22 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <unistd.h>

int main()
{
    {
        try{
        Bureaucrat b1(6, "Alice");
        PresidentialPardonForm  f1("TopSecret"); 

        b1.signForm(f1);  
        b1.executeForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    {
        try{
        Bureaucrat b1(5, "Alice");
        PresidentialPardonForm  f1("TopSecret"); 

        b1.signForm(f1);  
        b1.executeForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    {
        Bureaucrat b1(146, "Alice");
        ShrubberyCreationForm  f1("My Home");
        try{
            b1.signForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        b1.operator--();
        std::cout << b1.getGrade() <<std::endl;
        b1.signForm(f1);
        try{
            b1.executeForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        for (int  i = 0; i < 8; i++)
            b1.operator--();
        std::cout << b1.getGrade() <<std::endl;
        b1.executeForm(f1);
    }
    {
        Bureaucrat b1(45, "Alice");
        RobotomyRequestForm  f1("My Home");
        try{
        b1.signForm(f1);
        b1.executeForm(f1);
        sleep(1.5);
        b1.executeForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
}
