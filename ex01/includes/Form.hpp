/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:26:37 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/21 09:43:07 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    public:
        Form();
        Form(const std::string& name, const unsigned int gradeToSign, 
        const unsigned int gradeToExec);
        Form(const Form &form);
        Form& operator=(const Form &form);
        ~Form();

        std::string     getName() const;
        bool            getIsSign() const;
        unsigned int    getGradeToSign() const;
        unsigned int    getGradeToExec() const;
        void            beSigned(const Bureaucrat &bureaucrat);
        
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
        class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
    
        private:
        const std::string   _name;
        bool                _is_signed;
        const unsigned int  _gradeToSign;
        const unsigned int  _gradeToExec;
};
std::ostream& operator<<(const std::ostream &out, const Form &form);
#endif 