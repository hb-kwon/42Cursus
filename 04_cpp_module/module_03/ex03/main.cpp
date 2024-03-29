/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:21:59 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/15 20:32:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Inheritance
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a("A");

	std::cout << std::endl;
	a.whoAmI();

	std::cout << std::endl;
	{
		DiamondTrap b("B");
		DiamondTrap c("C");


		std::cout << std::endl;

		b.whoAmI();
		c.whoAmI();
		c.highFivesGuys();

		std::cout << std::endl;

		b.attack("C");
		c.takeDamage(b.getAttackDamage());

		std::cout << std::endl;

		b.attack("C");
		c.takeDamage(b.getAttackDamage());

		std::cout << std::endl;

		b.guardGate();

		std::cout << std::endl;
	}

	std::cout << "===============" << std::endl;

	DiamondTrap d;

	std::cout << std::endl;

	d.whoAmI();

	std::cout << std::endl;

	d = a;

	std::cout << std::endl;

	d.whoAmI();

	std::cout << std::endl;
	return (0);
}
