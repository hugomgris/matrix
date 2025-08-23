/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:00:00 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/23 10:00:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex15 main - Complex Vector Spaces

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "../Complex.hpp"

void test_complex_basic_operations() {
	std::cout << "\033[0;33mCOMPLEX NUMBER BASIC OPERATIONS--------\033[0m" << std::endl;
	
	Complex<float> z1(3.0f, 4.0f); 
	Complex<float> z2(1.0f, -2.0f);
	
	std::cout << "z1 = " << z1 << std::endl;
	std::cout << "z2 = " << z2 << std::endl;
	std::cout << "z1 + z2 = " << (z1 + z2) << std::endl;
	std::cout << "z1 - z2 = " << (z1 - z2) << std::endl;
	std::cout << "z1 * z2 = " << (z1 * z2) << std::endl;
	std::cout << "z1 / z2 = " << (z1 / z2) << std::endl;
	std::cout << "|z1| = " << z1.magnitude() << std::endl;
	std::cout << "conjugate(z1) = " << z1.conjugate() << std::endl;
	std::cout << std::endl;
}

void test_complex_vectors_ex00() {
	std::cout << "\033[0;33mEX00: COMPLEX VECTOR OPERATIONS--------\033[0m" << std::endl;
	
	Vector<Complex<float>> u = {
		Complex<float>(1.0f, 2.0f),
		Complex<float>(3.0f, -1.0f),
		Complex<float>(0.0f, 5.0f)
	};
	
	Vector<Complex<float>> v = {
		Complex<float>(2.0f, 1.0f),
		Complex<float>(-1.0f, 3.0f),
		Complex<float>(4.0f, 0.0f)
	};

	std::cout << "Complex vector u:" << std::endl;
	u.print();
	std::cout << "Complex vector v:" << std::endl;
	v.print();
	std::cout << std::endl;

	Vector<Complex<float>> sum_result = add(u, v);
	std::cout << "u + v = " << std::endl;
	sum_result.print();

	Vector<Complex<float>> sub_result = sub(u, v);
	std::cout << "u - v = " << std::endl;
	sub_result.print();

	Complex<float> scalar(2.0f, 1.0f);
	Vector<Complex<float>> scl_result = scl(u, scalar);
	std::cout << "(" << scalar << ") * u = " << std::endl;
	scl_result.print();
	std::cout << std::endl;
}

void test_complex_vectors_ex01() {
	std::cout << "\033[0;33mEX01: COMPLEX LINEAR COMBINATION--------\033[0m" << std::endl;
	
	Vector<Complex<float>> u = {
		Complex<float>(1.0f, 0.0f),
		Complex<float>(0.0f, 1.0f)
	};
	
	Vector<Complex<float>> v = {
		Complex<float>(0.0f, 1.0f),
		Complex<float>(1.0f, 0.0f)
	};

	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();

	std::vector<Vector<Complex<float>>> vectors = {u, v};
	std::vector<Complex<float>> coeffs = {
		Complex<float>(2.0f, 1.0f),
		Complex<float>(1.0f, -1.0f) 
	};

	std::cout << "Coefficients: [" << coeffs[0] << ", " << coeffs[1] << "]" << std::endl;

	Vector<Complex<float>> result = linear_combination(vectors, coeffs);
	std::cout << "Linear combination result:" << std::endl;
	result.print();
	std::cout << std::endl;
}

void test_complex_vectors_ex03() {
	std::cout << "\033[0;33mEX03: COMPLEX DOT PRODUCT--------\033[0m" << std::endl;
	
	Vector<Complex<float>> u = {
		Complex<float>(1.0f, 2.0f),
		Complex<float>(3.0f, -1.0f)
	};
	
	Vector<Complex<float>> v = {
		Complex<float>(2.0f, 1.0f),
		Complex<float>(-1.0f, 3.0f)
	};

	std::cout << "u:" << std::endl;
	u.print();
	std::cout << "v:" << std::endl;
	v.print();

	Complex<float> dot_result = dot(u, v);
	std::cout << "u · v = " << dot_result << std::endl;
	std::cout << std::endl;
}

void test_complex_vectors_ex04() {
	std::cout << "\033[0;33mEX04: COMPLEX VECTOR NORMS--------\033[0m" << std::endl;
	
	Vector<Complex<float>> u = {
		Complex<float>(3.0f, 4.0f),
		Complex<float>(0.0f, -5.0f),
		Complex<float>(12.0f, 0.0f)
	};

	std::cout << "u:" << std::endl;
	u.print();

	auto norm1 = norm_1(u);
	auto norm2 = norm(u);
	auto norm_inf_result = norm_inf(u);

	std::cout << "||u||₁ = " << norm1 << std::endl;
	std::cout << "||u||₂ = " << norm2 << std::endl;
	std::cout << "||u||∞ = " << norm_inf_result << std::endl;
	std::cout << std::endl;
}

void test_complex_matrices_ex07() {
	std::cout << "\033[0;33mEX07: COMPLEX MATRIX-VECTOR MULTIPLICATION--------\033[0m" << std::endl;
	
	Matrix<Complex<float>> A(2, 2, {
		Complex<float>(1.0f, 1.0f),
		Complex<float>(2.0f, 0.0f),
		Complex<float>(0.0f, -1.0f),
		Complex<float>(3.0f, 2.0f)
	});

	Vector<Complex<float>> u = {
		Complex<float>(1.0f, 0.0f),
		Complex<float>(0.0f, 1.0f)
	};

	std::cout << "Matrix A:" << std::endl;
	A.print();
	std::cout << "Vector u:" << std::endl;
	u.print();

	Vector<Complex<float>> result = mul_vec(A, u);
	std::cout << "A * u = " << std::endl;
	result.print();
	std::cout << std::endl;
}

void test_complex_matrices_ex08() {
	std::cout << "\033[0;33mEX08: COMPLEX MATRIX TRACE--------\033[0m" << std::endl;
	
	Matrix<Complex<float>> A(3, 3, {
		Complex<float>(1.0f, 2.0f),
		Complex<float>(0.0f, 1.0f),
		Complex<float>(2.0f, 0.0f), 
		Complex<float>(3.0f, -1.0f),
		Complex<float>(4.0f, 0.0f),
		Complex<float>(1.0f, 1.0f),
		Complex<float>(0.0f, 0.0f),
		Complex<float>(2.0f, 3.0f),
		Complex<float>(-1.0f, 5.0f)
	});

	std::cout << "Matrix A:" << std::endl;
	A.print();

	Complex<float> trace_result = trace(A);
	std::cout << "trace(A) = " << trace_result << std::endl;
	std::cout << std::endl;
}

void test_complex_matrices_ex11() {
	std::cout << "\033[0;33mEX11: COMPLEX MATRIX DETERMINANT--------\033[0m" << std::endl;
	
	Matrix<Complex<float>> A(2, 2, {
		Complex<float>(1.0f, 1.0f),
		Complex<float>(2.0f, 0.0f),
		Complex<float>(0.0f, -1.0f),
		Complex<float>(3.0f, 2.0f)
	});

	std::cout << "Matrix A:" << std::endl;
	A.print();

	Complex<float> det_result = determinant(A);
	std::cout << "det(A) = " << det_result << std::endl;
	std::cout << std::endl;
}

void test_hermitian_operations() {
	std::cout << "\033[0;33mHERMITIAN MATRIX OPERATIONS--------\033[0m" << std::endl;
	
	// Hermitian matrix (A = A*)
	Matrix<Complex<float>> H(2, 2, {
		Complex<float>(5.0f, 0.0f),
		Complex<float>(3.0f, 4.0f),
		Complex<float>(3.0f, -4.0f),
		Complex<float>(2.0f, 0.0f)
	});

	std::cout << "Hermitian matrix H:" << std::endl;
	H.print();

	Matrix<Complex<float>> H_transpose = transpose(H);
	std::cout << "Transpose of H:" << std::endl;
	H_transpose.print();

	std::cout << "Note: For Hermitian matrices, H = H* (conjugate transpose)" << std::endl;
	std::cout << std::endl;
}

int main(void) {
	try {
		test_complex_basic_operations();
		test_complex_vectors_ex00();
		test_complex_vectors_ex01();
		test_complex_vectors_ex03();
		test_complex_vectors_ex04();
		test_complex_matrices_ex07();
		test_complex_matrices_ex08();
		test_complex_matrices_ex11();
		test_hermitian_operations();
	} catch (const std::exception &e) {
		std::cerr << "\033[0;31mError: " << e.what() << "\033[0m" << std::endl;
		return 1;
	}

	return 0;
}
