/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:57:11 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 10:06:08 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    {
        try {
            Bureaucrat b1(50, "Alice");
            Form f1("TopSecret", 45, 50);
            std::cout << std::endl;
            b1.signForm(f1);  
            
            std::cout << std::endl << std::endl;
            Bureaucrat b2(40, "Bob");
            std::cout << std::endl;
            b2.signForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    {
        try {
            Bureaucrat b1(100, "Alice");
            Form f1("TopSecret", 100, 100);
            std::cout << std::endl;
            b1.signForm(f1);
            
            std::cout << std::endl << std::endl;
            Bureaucrat b2(40, "Bob");
            std::cout << std::endl;
            b2.signForm(f1);
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } 
    }
}