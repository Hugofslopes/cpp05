/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:08:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 14:57:06 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(){
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const std::string& name, unsigned int gradeToSign)
    : _name(name), _is_signed(false)
{
    if (gradeToSign < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150)
        throw GradeTooLowException();
    _is_signed = 1;
    std::cout << "Parametrized AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name){
_is_signed = other._is_signed;
    std::cout << "Copy AForm constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other){
    if (this != &other)
        _is_signed = other._is_signed;
    std::cout << "Copy assigment operator constructor called" << std::endl;        
    return (*this);    
}

AForm::~AForm(){
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const{
    return(_name);
}

bool AForm::getIsSign() const{
    return(_is_signed);
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    std::cout << bureaucrat.getGrade() << std::endl << std::endl;
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _is_signed = 1;
}

std::ostream& operator<<(std::ostream &out, const AForm &AForm)
{
    out << AForm.getName() << AForm.getIsSign() << std::endl;
    return (out);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too high");
}

void AForm::setGradeToSign(unsigned int value){
    _gradeToSign = value;
}

void AForm::setGradeToExec(unsigned int value){
    _gradeToExec = value;
}

unsigned int AForm::getGradeToExec() const{
    return(_gradeToExec);
}

void AForm::setName(std::string name){
    _name = name;
}