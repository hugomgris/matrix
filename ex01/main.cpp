/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/20 17:15:07 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex01 main

#include "../Vector.hpp"

int main(void) {
	Vector<float> u = {1, 2};
	Vector<float> v = {3, 1};
	Vector<float> w = {0, 4};

	std::cout << "\033[0;33mTest vectors-----------\033[0m" << std::endl;
	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();
	std::cout << "w:" << std::endl;
	w.print();
	std::cout << std::endl;

	std::cout << "\033[0;33mCoefficients-----------\033[0m" << std::endl;
	std::cout << "{";
	std::vector<float> coeffs = {2.0f, -1.5f, 0.5f};
	auto it = coeffs.begin();
	while (it != coeffs.end()) {
		std::cout << *it;
		if (*it != coeffs[coeffs.size() - 1]) { std::cout << ", "; }
		it++;
	}
	std::cout << "}" << std::endl;

	std::cout << "\033[0;33mLinear combination test-----------\033[0m" << std::endl;
	std::vector<Vector<float>> vectors;
	vectors.push_back(u);
	vectors.push_back(v);
	vectors.push_back(w);
	Vector<float> lcv = linear_combination(vectors, coeffs);
	lcv.print();

	std::cout << "\033[0;33mEdge cases tests-----------\033[0m" << std::endl;
	std::cout << "Different amount of vectors and scalars:" << std::endl;
	std::vector<Vector<float>> vectors2;
	vectors2.push_back(u);
	vectors2.push_back(v);
	try {
		Vector<float> lcv2 = linear_combination(vectors2, coeffs);
		lcv2.print();
	} catch (const std::invalid_argument &e) {
		std::cout << "Caught exception:" << e.what() << std::endl;
	}

	std::cout << "Empty vectors:" << std::endl;
	std::vector<Vector<float>> vectors3;
	std::vector<float> coeffs2;
	try {
		Vector<float> lcv3 = linear_combination(vectors3, coeffs2);
		lcv3.print();
	} catch (const std::invalid_argument &e) {
		std::cout << "Caught exception:" << e.what() << std::endl;
	}
}