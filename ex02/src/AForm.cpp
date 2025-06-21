/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:08:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 10:28:51 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name("Default"), _is_signed(0), _gradeToSign(1), _gradeToExec(1)
{
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const unsigned int gradeToSign, 
    const unsigned int gradeToExec)
    : _name(name), _is_signed(false), _gradeToSign(gradeToSign), 
    _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150)
        throw GradeTooLowException();
    _is_signed = 1;
    std::cout << "Parametrized AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _is_signed(other._is_signed),
_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
    std::cout << "Copy Aform constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other){
    if (this != &other)
        _is_signed = other._is_signed;
    std::cout << "Copy Aform assigment operator constructor called" << std::endl;        
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

unsigned int AForm::getGradeToExec() const{
    return(_gradeToExec);
}

unsigned int AForm::getGradeToSign() const{
    return(_gradeToSign);
}

void AForm::setName(std::string name){
    _name = name;
}
void AForm::setGradeToSign(unsigned int value){
    _gradeToSign = value;
}

void AForm::setGradeToExec(unsigned int value){
    _gradeToExec = value;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _is_signed = 1;
}

std::ostream& operator<<(std::ostream &out, const AForm &form)
{
    out << "Name - " << form.getName() << std::endl <<
    "Is signed - " << form.getIsSign() << std::endl <<
    "Grade to execute - " << form.getGradeToExec() << std::endl <<
    "Grade to sign - " << form.getGradeToSign() << std::endl;
    return (out);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
