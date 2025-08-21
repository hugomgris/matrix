/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/21 17:42:41 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex06 main

#include "../Vector.hpp"

int main(void) {
	Vector<float> u = {1, 2, 3};
	Vector<float> v = {4, 5, 6};

	std::cout << "\033[0;33mTest vectors-----------\033[0m" << std::endl;
	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();

	std::cout << "\033[0;33mcross product test (u, v)-----------\033[0m" << std::endl;
	Vector<float> cp1 = cross_product(u, v);
	cp1.print();

	std::cout << "\033[0;33mAnti-commutativity test/proof (v, u)-----------\033[0m" << std::endl;
	Vector<float> cp2 = cross_product(v, u);
	cp2.print();

	std::cout << "\033[0;33mcross product test with basis vectors ({1, 0, 0}, {0, 1, 0})-----------\033[0m" << std::endl;
	Vector<float> cp3 = cross_product(Vector<float>({1, 0, 0}), Vector<float>({0, 1, 0}));
	cp3.print();

	std::cout << "\033[0;33mcross product test with paralel vectors ({1, 2, 3}, {2, 4, 6})-----------\033[0m" << std::endl;
	Vector<float> cp4 = cross_product(Vector<float>({1, 2, 3}), Vector<float>({2, 4, 6}));
	cp4.print();
	std::cout << "\033[0;33mtest with non-3D vectors-----------\033[0m" << std::endl;
	try {
		Vector<float> cp5 = cross_product(Vector<float>({1, 2, 3}), Vector<float>({2, 4}));
		cp5.print();
	} catch (const std::invalid_argument &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\033[0;33mPerpendicularity verification (should be 0)-----------\033[0m" << std::endl;
	Vector<float> cross_result = cross_product(u, v);
	std::cout << "(u × v) · u = " << dot(cross_result, u) << std::endl;
	std::cout << "(u × v) · v = " << dot(cross_result, v) << std::endl;
}