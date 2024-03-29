/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:10:04 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/22 16:55:04 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Default Constructor Cure" << std::endl;
}

Cure::Cure(std::string const type) : AMateria(type)
{
	std::cout << "Named Constructor Cure" << std::endl;
}

Cure::Cure(Cure const &cu) : AMateria(cu.getType())
{
}

Cure	&Cure::operator=(Cure const &cu)
{
	if (this != &cu)
		type = cu.getType();
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Destructor Cure" << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
