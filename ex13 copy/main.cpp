/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 18:57:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex15 main

#include "../Vector.hpp"
#include "../Matrix.hpp"

using Complex = std::complex<float>;
using ComplexD = std::complex<double>;

int main() {
    std::cout << "\033[0;35mComplex Vector Space Tests\033[0m" << std::endl;
    
    // Test 1: Complex Vector Operations
    std::cout << "\nTest 1: Complex Vector Operations" << std::endl;
    Vector<Complex> cv1({Complex(1, 2), Complex(3, -1), Complex(0, 5)});
    Vector<Complex> cv2({Complex(2, -1), Complex(1, 3), Complex(-2, 1)});
    
    std::cout << "Vector 1: ";
    cv1.print();
    std::cout << "Vector 2: ";
    cv2.print();
    
    auto sum = add(cv1, cv2);
    std::cout << "Sum: ";
    sum.print();
    
    auto scaled = scl(cv1, Complex(2, 1));
    std::cout << "Scaled by (2+i): ";
    scaled.print();
    
    // Test 2: Complex Dot Product
    std::cout << "\nTest 2: Complex Dot Product" << std::endl;
    auto dot_result = dot(cv1, cv2);
    std::cout << "Dot product: " << dot_result << std::endl;
    
    // Test 3: Complex Matrix Operations
    std::cout << "\nTest 3: Complex Matrix Operations" << std::endl;
    Matrix<Complex> cm1({
        {Complex(1, 0), Complex(0, 1)},
        {Complex(0, -1), Complex(1, 0)}
    });
    
    Matrix<Complex> cm2({
        {Complex(2, 1), Complex(1, -1)},
        {Complex(-1, 2), Complex(0, 1)}
    });
    
    std::cout << "Matrix 1:" << std::endl;
    cm1.print();
    std::cout << "Matrix 2:" << std::endl;
    cm2.print();
    
    auto product = mul_mat(cm1, cm2);
    std::cout << "Product:" << std::endl;
    product.print();
    
    // Test 4: Complex Determinant
    std::cout << "\nTest 4: Complex Determinant" << std::endl;
    auto det = determinant(cm1);
    std::cout << "Determinant of Matrix 1: " << det << std::endl;
    
    // Test 5: Complex Linear Interpolation
    std::cout << "\nTest 5: Complex Linear Interpolation" << std::endl;
    auto lerp_result = lerp(cv1, cv2, Complex(0.5, 0));
    std::cout << "LERP at t=0.5: ";
    lerp_result.print();
    
    // Test 6: Complex Projection Matrix
    std::cout << "\nTest 6: Complex Projection Matrix (demonstration)" << std::endl;
    auto complex_proj = projection<Complex>(Complex(60, 0), Complex(16.0/9.0, 0), 
                                           Complex(0.1, 0), Complex(100, 0));
    std::cout << "Complex projection matrix:" << std::endl;
    complex_proj.print();
    
    return 0;
}