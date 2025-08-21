/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/21 10:58:03 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex02 main

#include "../Vector.hpp"

int main(void) {
	Vector<float> u = {1, 2};
	Vector<float> v = {3, 1};
	Vector<float> w = {0, 4, 5};

	std::cout << "\033[0;33mTest vectors-----------\033[0m" << std::endl;
	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();
	std::cout << "w:" << std::endl;
	w.print();
	std::cout << std::endl;

	std::cout << "\033[0;33mLinear Interpolation Tests-----------\033[0m" << std::endl;
	std::cout << "u, v, t = 0" << std::endl;
	Vector<float> lerp1 = lerp(u, v, 0.0f);
	lerp1.print();
	std::cout << "u, v, t = 1" << std::endl;
	Vector<float> lerp2 = lerp(u, v, 1.0f);
	lerp2.print();
	std::cout << "u, v, t = 0.5" << std::endl;
	Vector<float> lerp3 = lerp(u, v, 0.5f);
	lerp3.print();

	std::cout << std::endl << "\033[0;33mEdge case tests-----------\033[0m" << std::endl;
	std::cout << "u and w with different sizes (should throw)" << std::endl;
	try {
		Vector<float> lerp4 = lerp(u, w, 0.5f);
		lerp4.print();
	} catch (const std::invalid_argument &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "same start andd end (should return shared values)" << std::endl;
	Vector<float> lerp5  = lerp(v, v, 0.5f);
	lerp5.print();
	std::cout << "extrapolation of t = 2 (should just work, overshoot 2x)" << std::endl;
	Vector<float> lerp6  = lerp(u, v, 2.0f);
	lerp6.print();
	std::cout << "extrapolation of t = -0.5 (should just work, undershoot 0.5x)" << std::endl;
	Vector<float> lerp7  = lerp(u, v, -0.5f);
	lerp7.print();
	std::cout << "extrapolation of t = 1.5 (150% to end)" << std::endl;
	Vector<float> lerp8 = lerp(u, v, 1.5f);
	lerp8.print();
}