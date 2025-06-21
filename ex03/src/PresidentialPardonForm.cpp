/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:20:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 11:12:16 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
	AForm::setGradeToExec(5);
	AForm::setGradeToSign(25);
	AForm::setName("PresidentialPardonForm");
	std::cout << "PP default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target){
	AForm::setGradeToExec(5);
	AForm::setGradeToSign(25);
	AForm::setName("PresidentialPardonForm");
	_target = target;
	std::cout << "PP parametrized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
: AForm(other) {
	_target = other._target;
	std::cout << "PP copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other)
		_target = other._target;
	return (*this);
	std::cout << "PP copy assignment constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

const char *PresidentialPardonForm::NotSignException::what() const throw()
{
	return ("Form is not signed");
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)  const{
	if (!getIsSign())
        throw NotSignException();
	if (executor.getGrade() > getGradeToExec())
        throw GradeTooHighException();
		
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

AForm *PresidentialPardonForm::createPForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}