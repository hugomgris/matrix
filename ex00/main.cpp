/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/20 16:14:12 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex00 main

#include "../Vector.hpp"

int main(void) {
	Vector<float> u = {1, 2, 3};
	Vector<float> v = {4, 5, 6};

	std::cout << "\033[0;33mTest vectors-----------\033[0m" << std::endl;
	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();
	std::cout << std::endl;

	Vector<float> sum_test = add(u, v);
	std::cout << "\033[0;33mADD test-------------------------\033[0m" << std::endl;
	std::cout << "addition:" << std::endl;
	sum_test.print();
	std::cout << "addition test with operator overload:" << std::endl;
	Vector<float> sum_test_operator = u + v;
	sum_test_operator.print();
	std::cout << std::endl;

	Vector<float> sub_test = sub(u, v);
	std::cout << "\033[0;33mSUB test-------------------------\033[0m" << std::endl;
	std::cout << "substraction:" << std::endl;
	sub_test.print();
	std::cout << "substraction test with operator overload:" << std::endl;
	Vector<float> sub_test_operator = u - v;
	sub_test_operator.print();
	std::cout << std::endl;

	Vector<float> scl_test = scl(u, 5.0f);
	std::cout << "\033[0;33mSCL test with scalar 5.0f--------\033[0m" << std::endl;
	std::cout << "scalar multiplication:" << std::endl;
	scl_test.print();
	std::cout << "scalar multiplication test with operator overload:" << std::endl;
	Vector<float> scl_test_operator = u * 5.0f;
	scl_test_operator.print();
	std::cout << std::endl;
}