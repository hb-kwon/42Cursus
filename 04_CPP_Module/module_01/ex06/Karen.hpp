/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:16:46 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/04 22:46:17 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <algorithm>
#include <string>

class Karen{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Karen();
		void complain(std::string level);
		~Karen();
};

#endif
