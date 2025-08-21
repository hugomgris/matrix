/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/21 14:54:25 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex04 main

#include "../Vector.hpp"

int main(void) {
	Vector<float> u = {3, -4, 2};
	Vector<float> v = {8, 0, 1};
	Vector<float> w = {-1, -2, -3};
	Vector<float> zero = {0, 0, 0};

	std::cout << "\033[0;33mTest vectors-----------\033[0m" << std::endl;
	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();
	std::cout << "w:" << std::endl;
	w.print();
	std::cout << "zero:" << std::endl;
	zero.print();
	std::cout << std::endl;

	std::cout << "\033[0;33mnorm_1 test (manhattan)-----------\033[0m" << std::endl;
	std::cout << "‖u‖₁ = " << norm_1(u) << std::endl;
	std::cout << "‖v‖₁ = " << norm_1(v) << std::endl;
	std::cout << "‖w‖₁ = " << norm_1(w) << std::endl;
	std::cout << "‖zero‖₁ = " << norm_1(zero) << std::endl;

	std::cout << "\033[0;33mnorm test (euclidean / hypotenuse)-----------\033[0m" << std::endl;
	std::cout << "‖u‖₂ = " << norm(u) << std::endl;
	std::cout << "‖v‖₂ = " << norm(v) << std::endl;
	std::cout << "‖w‖₂ = " << norm(w) << std::endl;
	std::cout << "‖zero‖₂ = " << norm(zero) << std::endl;

	std::cout << "\033[0;33msupremum norm test (maximum component)-----------\033[0m" << std::endl;
	std::cout << "‖u‖₂ = " << norm_inf(u) << std::endl;
	std::cout << "‖v‖₂ = " << norm_inf(v) << std::endl;
	std::cout << "‖w‖₂ = " << norm_inf(w) << std::endl;
	std::cout << "‖zero‖₂ = " << norm_inf(zero) << std::endl;
}