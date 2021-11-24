/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:49:57 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 20:34:18 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

//npos : size_type 으로 정의된 특수값
//find() 함수에 의해서 found 되지 못하는 경우 npos값이 리턴
int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Error : Argument check please" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string newLine;
	std::string str;
	std::ifstream infile(filename.data());
	if (!infile.is_open())
	{
		std::cout << "Error : Wrong File" << std::endl;
		return (1);
	}
	std::ofstream outfile(filename.append(".replace").data());
	if (!outfile.is_open())
	{
		infile.close();
		std::cout << "Error : File Open Fail" << std::endl;
		return (1);
	}
	while (true)
	{
		std::getline(infile, str);
		newLine = str;
		//std::size_type -> std::string, std::map, std::vector에서 size를 표현해준다.
		std::string::size_type start = 0;
		std::string::size_type index = 0;
		while ((index = str.find(s1, start)) != std::string::npos)
		{
			newLine.erase(index, s1.length());
			newLine.insert(index, s2);
			start = index + s1.length();
		}
		outfile << newLine;
		if (infile.eof())
			break ;
		outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
