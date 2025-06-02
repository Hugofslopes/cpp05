/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:16:50 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/02 18:36:40 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
	AForm::setGradeToExec(45);
	AForm::setGradeToSign(72);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target){
	AForm::setGradeToExec(45);
	AForm::setGradeToSign(72);
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other){
	_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other)
		_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::execute(Bureaucrat const & executor){
	srand(time(NULL));
	int randNum = rand() % 2;
	
	std::cout << "*drilling noises* " << std::endl;
	if (randNum)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}