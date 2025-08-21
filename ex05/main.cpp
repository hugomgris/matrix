/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/21 15:49:14 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex05 main

#include "../Vector.hpp"

int main(void) {
	Vector<float> u = {1, 2, 3};
	Vector<float> v = {4, 5, 6};
	Vector<float> perp1 = {1, 0};
	Vector<float> perp2 = {0, 1};
	Vector<float> parallel1 = {1, 2};
	Vector<float> parallel2 = {2, 4};
	Vector<float> opposite1 = {1, 2};
	Vector<float> opposite2 = {-1, -2};

	std::cout << "\033[0;33mTest vectors-----------\033[0m" << std::endl;
	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();
	std::cout << "perp1:" << std::endl;
	perp1.print();
	std::cout << "perp2:" << std::endl;
	perp2.print();
	std::cout << "parallel1:" << std::endl;
	parallel1.print();
	std::cout << "parallel2:" << std::endl;
	parallel2.print();
	std::cout << "opposite1:" << std::endl;
	opposite1.print();
	std::cout << "opposite2:" << std::endl;
	opposite2.print();

	std::cout << "\033[0;33mcos test (u, v)-----------\033[0m" << std::endl;
	std::cout << "cos(u, v)=" << angle_cos(u, v) << std::endl;
	std::cout << "cos(90° // perp1, perp2) = " << angle_cos(perp1, perp2) << std::endl;

	std::cout << "cos(0° // parallel1, parallel2) = " << angle_cos(parallel1, parallel2) << std::endl;
	
	std::cout << "cos(180° // opposite1, opposite2) = " << angle_cos(opposite1, opposite2) << std::endl;
}