/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:26:37 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/02 18:23:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const std::string& name, unsigned int gradeToSign);
        AForm(const AForm &AForm);
        AForm& operator=(const AForm &AForm);
        virtual ~AForm();

        std::string getName() const;
        void setGradeToSign(unsigned int value);
        void setGradeToExec(unsigned int value);
        bool getIsSign() const;
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor)=0;
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
        unsigned int  _gradeToSign;
        unsigned int  _gradeToExec;
};
std::ostream& operator<<(const std::ostream &out, const AForm &AForm);
#endif 