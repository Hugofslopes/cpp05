/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:50:59 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/02 13:59:04 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat{
    public:
        Bureaucrat();   
        Bureaucrat(unsigned int grade, const std::string name) ;       
        Bureaucrat(const Bureaucrat &Bureaucrat);
        Bureaucrat& operator=(const Bureaucrat &Bureaucrat);
        ~Bureaucrat();
        
        std::string getName() const;
        unsigned int getGrade() const;
        Bureaucrat& operator++(void);
        Bureaucrat& operator--(void);
        Bureaucrat& incrementGrade(void);
        Bureaucrat& decrementGrade(void);
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
        unsigned int        _grade;
};
std::ostream& operator<<(std::ostream &out, const  Bureaucrat &Bureaucrat);
#endif
