/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 10:23:41 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex07 main

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include <chrono>

int main(void) {
	Matrix<float> A(3, 2, {1, 2, 3, 4, 5, 6});
	Matrix<float> B(2, 2, {1, 2, 3, 4});
	Matrix<float> C(2, 3, {7, 8, 9, 10, 11, 12});
	Vector<float> u({5, 6});

	std::cout << "\033[0;33mTest data-----------\033[0m" << std::endl;
	std::cout << "Matrix A:" << std::endl;
	A.print();
	std::cout << "Matrix B:" << std::endl;
	B.print();
	std::cout << "Matrix C:" << std::endl;
	C.print();
	std::cout << "Vector u:" << std::endl;
	u.print();

	std::cout << "\033[0;33mcMatrix - vector multiplication test (Axu)-----------\033[0m" << std::endl;
	Vector<float> r1 = mul_vec(A, u);
	r1.print();

	std::cout << "\033[0;33mcMatrix - Matrix multiplication test (BxC)-----------\033[0m" << std::endl;
	Matrix<float> r2 = mul_mat(B, C);
	r2.print();

	std::cout << "\033[0;33mError handling tests-----------\033[0m" << std::endl;
	try {
		Vector<float> wrong_size({1, 2, 3});
		Vector<float> error_result = mul_vec(A, wrong_size);
	} catch (const std::invalid_argument& e) {
		std::cout << "✅ Matrix-vector dimension error caught: " << e.what() << std::endl;
	}

	try {
		Matrix<float> wrong_dim(3, 3, {1,2,3,4,5,6,7,8,9});
		Matrix<float> error_result = mul_mat(wrong_dim, B);
	} catch (const std::invalid_argument& e) {
		std::cout << "✅ Matrix-matrix dimension error caught: " << e.what() << std::endl;
	}

	std::cout << "\033[0;33mIdentity matrix tests-----------\033[0m" << std::endl;
	Matrix<float> I2(2, 2, {1, 0, 0, 1});
	std::cout << "Identity matrix I2:" << std::endl;
	I2.print();

	Vector<float> test_vec({7, 8});
	Vector<float> identity_result = mul_vec(I2, test_vec);
	std::cout << "I2 × vector (should be same as input):" << std::endl;
	identity_result.print();

	Matrix<float> identity_mat_result = mul_mat(I2, B);
	std::cout << "I2 × B (should be same as B):" << std::endl;
	identity_mat_result.print();

	std::cout << "\033[0;33mZero matrix tests-----------\033[0m" << std::endl;
	Matrix<float> Zero(2, 2, {0, 0, 0, 0});
	std::cout << "Zero matrix:" << std::endl;
	Zero.print();

	Vector<float> zero_vec_result = mul_vec(Zero, test_vec);
	std::cout << "Zero × vector (should be zero vector):" << std::endl;
	zero_vec_result.print();

	Matrix<float> zero_mat_result = mul_mat(Zero, B);
	std::cout << "Zero × matrix (should be zero matrix):" << std::endl;
	zero_mat_result.print();

	std::cout << "\033[0;33mMatrix chain multiplication test-----------\033[0m" << std::endl;
	Matrix<float> BC = mul_mat(B, C);
	std::cout << "B × C (2×2 × 2×3 = 2×3):" << std::endl;
	BC.print();

	Matrix<float> A_BC = mul_mat(A, BC);
	std::cout << "A × (B × C) (3×2 × 2×3 = 3×3):" << std::endl;
	A_BC.print();

	std::cout << "\033[0;33mManual verification tests-----------\033[0m" << std::endl;
	Matrix<float> Simple(2, 2, {1, 2, 3, 4});
	Vector<float> SimpleVec({5, 6});

	std::cout << "Simple matrix:" << std::endl;
	Simple.print();
	std::cout << "Simple vector:" << std::endl;
	SimpleVec.print();

	Vector<float> simple_result = mul_vec(Simple, SimpleVec);
	std::cout << "Result (should be [17, 39]):" << std::endl;
	simple_result.print();
	// Manual: [1×5 + 2×6, 3×5 + 4×6] = [17, 39]

	Matrix<float> Simple2(2, 2, {1, 2, 3, 4});
	Matrix<float> simple_mat_result = mul_mat(Simple, Simple2);
	std::cout << "Simple × Simple (should be [7, 10; 15, 22]):" << std::endl;
	simple_mat_result.print();
	// Manual: [[1×1+2×3, 1×2+2×4], [3×1+4×3, 3×2+4×4]] = [[7,10], [15,22]]

	std::cout << "\033[0;33mPerformance test-----------\033[0m" << std::endl;
	std::vector<float> large_data;
	for (int i = 0; i < 100; ++i) {
		large_data.push_back(static_cast<float>(i % 10));
	}

	Matrix<float> Large1(10, 10, large_data);
	Matrix<float> Large2(10, 10, large_data);

	auto start = std::chrono::high_resolution_clock::now();
	Matrix<float> large_result = mul_mat(Large1, Large2);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "10×10 matrix multiplication took: " << duration.count() << " microseconds" << std::endl;

	std::cout << "\033[0;33mSingle element tests-----------\033[0m" << std::endl;
	Matrix<float> Single(1, 1, {5.0f});
	Vector<float> SingleVec({3.0f});

	Vector<float> single_result = mul_vec(Single, SingleVec);
	std::cout << "1×1 matrix × 1×1 vector = " << single_result[0] << " (should be 15)" << std::endl;

	Matrix<float> Single2(1, 1, {4.0f});
	Matrix<float> single_mat_result = mul_mat(Single, Single2);
	std::cout << "1×1 × 1×1 matrix = " << single_mat_result(0,0) << " (should be 20)" << std::endl;

	std::cout << "\033[0;33mRectangular matrix tests-----------\033[0m" << std::endl;
	Matrix<float> Wide(2, 5, {1,2,3,4,5, 6,7,8,9,10});
	Vector<float> WideVec({1,1,1,1,1});

	std::cout << "Wide matrix (2×5):" << std::endl;
	Wide.print();

	Vector<float> wide_result = mul_vec(Wide, WideVec);
	std::cout << "Wide × vector result:" << std::endl;
	wide_result.print();

	Matrix<float> Tall(5, 2, {1,2, 3,4, 5,6, 7,8, 9,10});
	Vector<float> TallVec({2, 3});

	std::cout << "Tall matrix (5×2):" << std::endl;
	Tall.print();

	Vector<float> tall_result = mul_vec(Tall, TallVec);
	std::cout << "Tall × vector result:" << std::endl;
	tall_result.print();
}