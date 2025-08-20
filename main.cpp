/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:14:15 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/20 11:58:19 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrix.hpp"
#include "Vector.hpp"

int main(void) {
	std::cout << "3x2 vector test:" << std::endl;
	Vector<float> v1 = Vector<float>({3, 2});
	v1.print();

	std::cout << std::endl << "3x2 size constructed matrix test:" << std::endl;
	Matrix<float> m1 = Matrix<float>(3, 2);
	m1.print();

	std::cout << std::endl << "Matrix test with inconsistent rows (initializer list constructor):" << std::endl;
	try {
		Matrix<float> m2 = Matrix<float>({{1, 2, 3}, {4, 5}});
		m2.print();
	} catch (const std::runtime_error &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Matrix square test (should be false - 0):" << std::endl;
	m1.print();
	std::cout << m1.isSquare() << std::endl;

	std::cout << std::endl << "Matrix square test (should be true - 1):" << std::endl;
	Matrix<float> m3 = Matrix<float>({{1, 2, 3}, {4, 5, 6}});
	m3.print();
	std::cout << m3.isSquare() << std::endl;

	std::cout << std::endl << "Matrix shape test for a 3x3 matrix:" << std::endl;
	std::cout << m3.getShape().first << "-" << m3.getShape().second << std::endl;

	std::cout << std::endl << "Matrix access test with [] operator:" << std::endl;
	std::cout << "Accessing m3[4] should be 5 and its: " << m3[4] << std::endl;

	std::cout << std::endl << "Matrix access test with () operator:" << std::endl;
	std::cout << "Accessing m3(1, 1) should be 5 and its: " << m3(1, 1) << std::endl;

	std::cout << std::endl << "Matrix to Vector conversion test:" << std::endl;
	m3.toVector().print();

	std::cout << std::endl << "Matrix copy constructor (and assignment operator) test:" << std::endl;
	Matrix<float> m4 = m3;
	std::cout << "Base matrix print:" << std::endl;
	m3.print();
	std::cout << std::endl << "Copied matrix print:" << std::endl;
	m4.print();

	std::cout << std::endl << "Vector conversion to matrix test:" << std::endl;
	Vector<float> v2 = Vector<float>({1, 2, 3, 4, 5, 6});
	Matrix<float> m5 = v2.toMatrix();
	std::cout << "Vector print:" << std::endl;
	v2.print();
	std::cout << std::endl << "Matrix print:" << std::endl;
	m5.print();
}