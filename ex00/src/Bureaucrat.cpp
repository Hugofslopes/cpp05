/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:14:06 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/02 14:32:53 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade, const std::string name)
: _name(name){
    if (grade < 1) 
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();;
    _grade = grade;
    std::cout << "Parametrized bureaucrat constructor called" << std::endl;
    
}   

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other._name), _grade(other._grade){
    std::cout << "Copy bureaucrat constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    std::cout << "Copy assign operator bureaucrat constructor called" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const{
    return (_name);
}

unsigned int Bureaucrat::getGrade() const{
    return (_grade);
}

Bureaucrat& Bureaucrat::operator++(void){
    ++_grade;
    if (_grade < 1) 
        throw Bureaucrat::GradeTooLowException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooHighException();;
    return (*this);
}

Bureaucrat& Bureaucrat::operator--(void){
    --_grade;
    if (_grade < 1) 
        throw Bureaucrat::GradeTooLowException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooHighException();;
    return (*this);
}

Bureaucrat& Bureaucrat::incrementGrade(void){
    return(--(*this));
}

Bureaucrat& Bureaucrat::decrementGrade(void){
    return(++(*this));
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too low");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too high");
}

std::ostream& operator<<(std::ostream &out, const  Bureaucrat &Bureaucrat){
    out << Bureaucrat.getName() << " bureaucrat grade " << 
    Bureaucrat.getGrade() << std::endl;
	return (out);
}
