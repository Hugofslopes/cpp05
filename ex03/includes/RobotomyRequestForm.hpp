/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:17:33 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 14:49:09 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor)  const;
		
	private:
		std::string _target;
		class NotSignException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
#endif
