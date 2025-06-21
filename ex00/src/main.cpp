/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:57:11 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 09:13:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    {
        try {
            Bureaucrat a(150, "Mr Lopes");
            std::cout << a << std::endl;
            
            Bureaucrat b(151, "Mr Sousa");
            std::cout << b << std::endl;
            
            Bureaucrat c(0, "Mr Man");
            std::cout << c << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    {
        try {
            Bureaucrat a(1, "Mr Lopes");
            std::cout << a << std::endl;
            
            Bureaucrat c(0, "Mr Man");
            std::cout << c << std::endl;
            
            Bureaucrat b(151, "Mr Sousa");
            std::cout << b << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        Bureaucrat a(1, "Mr Lopes");
        std::cout << a << std::endl;
        try {
            --a;
        }
        catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
