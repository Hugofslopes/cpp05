/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:20:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 17:50:15 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
	AForm::setGradeToExec(5);
	AForm::setGradeToSign(25);
	AForm::setName("PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target){
	AForm::setGradeToExec(5);
	AForm::setGradeToSign(25);
	AForm::setName("PresidentialPardonForm");
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
: AForm(other) {
	_target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other)
		_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	
}

const char *PresidentialPardonForm::NotSignException::what() const throw()
{
	return ("Form is no sign");
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

