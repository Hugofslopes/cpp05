/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:20:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/02 18:32:29 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
	AForm::setGradeToExec(45);
	AForm::setGradeToSign(72);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target){
	AForm::setGradeToExec(45);
	AForm::setGradeToSign(72);
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other){
	_target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other)
		_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor){
	
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
