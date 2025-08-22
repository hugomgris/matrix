/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 11:23:15 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex08 main

#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(void) {
	Matrix<float> A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

	std::cout << "\033[0;33mInitial Test data-----------\033[0m" << std::endl;
	std::cout << "Matrix A:" << std::endl;
	A.print();

	std::cout << "\033[0;33mBasic Trace test-----------\033[0m" << std::endl;
	std::cout << "A matrix trace = " << trace(A) << std::endl;

	std::cout << "\033[0;33mExtended Trace tests-----------\033[0m" << std::endl;

	Matrix<float> I3(3, 3, {1,0,0, 0,1,0, 0,0,1});
	float trace_identity = trace(I3);
	std::cout << "trace(I₃) = " << trace_identity << " (should be 3)" << std::endl;

	Matrix<float> simple(2, 2, {1, 2, 3, 4});
	float trace_simple = trace(simple);
	std::cout << "trace(Simple) = " << trace_simple << " (should be 5)" << std::endl;

	Matrix<float> zero(2, 2, {0, 0, 0, 0});
	float trace_zero = trace(zero);
	std::cout << "trace(Zero) = " << trace_zero << " (should be 0)" << std::endl;

	Matrix<float> diagonal(3, 3, {2,0,0, 0,3,0, 0,0,5});
	float trace_diagonal = trace(diagonal);
	std::cout << "trace(Diagonal) = " << trace_diagonal << " (should be 10)" << std::endl;

	try {
		Matrix<float> nonSquare(2, 3, {1,2,3, 4,5,6});
		float error_trace = trace(nonSquare);
		std::cout << "trace(nonSquare) = " << error_trace << " (should throw)" << std::endl;
	} catch (const std::invalid_argument& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}