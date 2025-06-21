/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:08:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 10:02:28 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("Default"), _is_signed(0), _gradeToSign(1), _gradeToExec(1)
{
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const std::string& name, const unsigned int gradeToSign, 
    const unsigned int gradeToExec)
    : _name(name), _is_signed(false), _gradeToSign(gradeToSign), 
    _gradeToExec(gradeToExec)
{
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    else if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "Parametrized form constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed),
_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
    std::cout << "Copy form constructor called" << std::endl;
}

Form& Form::operator=(const Form &other){
    if (this != &other)
        _is_signed = other._is_signed;
    std::cout << "Copy assigment operator constructor called" << std::endl;        
    return (*this);    
}

Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const{
    return(_name);
}

bool Form::getIsSign() const{
    return(_is_signed);
}

unsigned int    Form::getGradeToSign() const{
    return (_gradeToSign);
}

unsigned int    Form::getGradeToExec() const
{
    return (_gradeToExec);
}

void Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _is_signed = 1;
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
    out << "Name - " << form.getName() << std::endl <<
    "Is signed - " << form.getIsSign() << std::endl <<
    "Grade to execute - " << form.getGradeToExec() << std::endl <<
    "Grade to sign - " << form.getGradeToSign() << std::endl;
    return (out);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
} 

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
