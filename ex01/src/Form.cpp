/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:08:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/02 14:54:27 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(){
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const std::string& name, unsigned int gradeToSign)
    : _name(name), _is_signed(false)
{
    if (gradeToSign < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150)
        throw GradeTooLowException();
    _is_signed = 1;
    std::cout << "Parametrized form constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name){
_is_signed = other._is_signed;
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

void Form::beSigned(const Bureaucrat &bureaucrat){
    std::cout << bureaucrat.getGrade() << std::endl << std::endl;
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _is_signed = 1;
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << form.getIsSign() << std::endl;
    return (out);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too low");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too high");
}
