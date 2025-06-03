/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:30:27 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 17:57:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other){
	*this = other;
}
Intern& Intern::operator=(const Intern &other){
	if (this != &other)
		return (*this);
	return (*this);
}


const char *Intern::makeFormException::what() const throw()
{
	return ("Grade is too high");
}

AForm* Intern::makeForm(std::string formName, std::string formTarget){
    AForm *(*form[3])(std::string const &target) = {
        &ShrubberyCreationForm::creatSForm,
        &RobotomyRequestForm::creatRForm,
        &PresidentialPardonForm::createPForm
    };

    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (form[i](formTarget));
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    throw makeFormException();
}