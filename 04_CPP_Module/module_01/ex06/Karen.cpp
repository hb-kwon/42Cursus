/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:16:37 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 21:21:58 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
이전 문제에서 크게 벗어날 필요 없이 멤버 함수 포인터를 담은 배열과 std::string을 담은 배열에 Filtering을 위한 함수와 요소를 각각 추가하면 된다.
지정된 Level 이상의 Logging들을 출력해야 하므로,
현재 Level을 찾은 뒤에 Filtering만 아니라면 loop를 통해 찾은 Level 이상의 Logging들을 간단히 출력할 수 있다.
*/
=======
/*   Updated: 2021/12/28 23:52:33 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Member func pointer
//함수의 포인터를 가지고 있는 것
//호출방법 : 명시적 & 암묵적
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

	void (Karen:: *funcPtr[4])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};

	std::string *level_ptr = std::find(comp, comp + 4, level);
	int index = level_ptr - comp;

	switch(index)
	{
		case 0:
			(this->*funcPtr[0])();
		case 1:
			(this->*funcPtr[1])();
		case 2:
			(this->*funcPtr[2])();
		case 3:
			(this->*funcPtr[3])();
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

Karen::~Karen(){
}
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
