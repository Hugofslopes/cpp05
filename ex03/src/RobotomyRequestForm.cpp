/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:16:50 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 11:12:59 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
	AForm::setGradeToExec(45);
	AForm::setGradeToSign(72);
	AForm::setName("RobotomyRequestForm");
	std::cout << "RR default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target){
	AForm::setGradeToExec(45);
	AForm::setGradeToSign(72);
	AForm::setName("RobotomyRequestForm");
	_target = target;
	std::cout << "RR parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other) {
	_target = other._target;
	std::cout << "RR copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other)
		_target = other._target;
	return (*this);
	std::cout << "RR copy assignment constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

const char *RobotomyRequestForm::NotSignException::what() const throw()
{
	return ("Form is not signed");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)  const{
	if (!getIsSign())
        throw NotSignException();
    if (executor.getGrade() > getGradeToExec())
        throw GradeTooHighException();

    std::cout << "*drilling noises*" << std::endl;

    std::time_t t = std::time(0);
    if (t % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << _target << " robotomization failed." << std::endl;
}

AForm *RobotomyRequestForm::creatRForm(std::string const &target){
	return (new RobotomyRequestForm(target));
}