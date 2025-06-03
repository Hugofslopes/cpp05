/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:30:59 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 16:12:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

class Aform;
class Bureucrat;

class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);

		AForm* makeForm(std::string formName, std::string formTarget);
		class makeFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
#endif
