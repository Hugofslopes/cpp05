/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:58:48 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 10:33:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){
	AForm::setGradeToExec(137);
	AForm::setGradeToSign(145);
	AForm::setName("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target){
	AForm::setGradeToExec(137);
	AForm::setGradeToSign(145);
	_target = target;
	AForm::setName("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
: AForm(other){
	_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other)
		_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

const char *ShrubberyCreationForm::NotSignException::what() const throw()
{
	return ("Form is not signed");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)  const{
	if (!getIsSign())
        throw NotSignException();
	if (executor.getGrade() > getGradeToExec())
        throw GradeTooHighException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file) {
        std::cerr << "Error: Could not create file \"" << (_target + "_shrubbery").c_str() 
		<< "\"." << std::endl;
        return ;
    }
	file << "   /\\   " << std::endl;	
	file << "  /**\\  " << std::endl;
	file << " /****\\ " << std::endl;
	file << "/******\\" << std::endl;
	file << "  ||||   " << std::endl;
	file << "  ||||   " << std::endl;
	file.close();
}