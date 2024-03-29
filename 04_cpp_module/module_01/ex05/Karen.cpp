/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:44:13 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/09 22:20:56 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(){
}

void Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	std::string	comp[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	void (Karen::*funcPtr[4])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};

	for(int i = 0; i < 4; i++)
		if (level.compare(comp[i]) == 0)
			(this->*funcPtr[i])();
}

Karen::~Karen(){
}
