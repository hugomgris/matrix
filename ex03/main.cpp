/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/21 12:48:08 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex03 main

#include "../Vector.hpp"

int main(void) {
	Vector<float> u = {1, 2, 3};
	Vector<float> v = {4, 5, 6};
	Vector<float> u2 = {2, 1};
	Vector<float> v2 = {-1, 2};
	Vector<float> zero = {0, 0, 0};
	Vector<float> opposite = {-1, -2, -3};

	std::cout << "\033[0;33mTest vectors-----------\033[0m" << std::endl;
	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();
	std::cout << "u2:" << std::endl;
	u2.print();
	std::cout << "v2:" << std::endl;
	v2.print();
	std::cout << "zero:" << std::endl;
	zero.print();
	std::cout << std::endl;	

	std::cout << "\033[0;33mDot product tests-----------\033[0m" << std::endl;
	std::cout << "u·v=" << dot(u, v) << std::endl;
	std::cout << "Zero vector with u: " << dot(u, zero) << std::endl;
	std::cout << "u with opposite: " << dot(u, opposite) << std::endl;

	std::cout << std::endl << "\033[0;33mEdge case tests-----------\033[0m" << std::endl;
	std::cout << "Vectors of different size (throw exception)" << std::endl;
	try {
		std::cout << dot(u, v2) << std::endl;
	} catch (const std::invalid_argument &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "Perpendicular vectors (u2·v2)" << std::endl;
	std::cout << dot(u2, v2) << std::endl;
	std::cout << "Vector with itself (u)" << std::endl;
	std::cout << dot(u2, u2) << std::endl;
}