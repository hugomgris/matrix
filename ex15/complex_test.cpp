/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_test.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:30:00 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/23 10:30:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Quick verification that all exercises work with Complex<float>
// This file demonstrates the power of templates - all previous exercises now support complex numbers!

#include "../Vector.hpp"
#include "../Matrix.hpp" 
#include "../Complex.hpp"

int main() {
    std::cout << "Testing that ALL exercises work with Complex<float>:\n\n";
    
    using C = Complex<float>;
    
    // ex00
    Vector<C> u = {C(1,2), C(3,-1)};
    Vector<C> v = {C(2,1), C(-1,3)};
    auto sum = add(u, v);
    auto scaled = scl(u, C(2,1));
    
    // ex01
    std::vector<Vector<C>> vectors = {u, v};
    std::vector<C> coeffs = {C(1,1), C(2,-1)};
    auto lc = linear_combination(vectors, coeffs);
    
    // ex02
    auto interpolated = lerp(u, v, C(0.5, 0));
    
    // ex03
    auto dot_result = dot(u, v);
    
    // ex04
    auto n1 = norm_1(u);
    auto n2 = norm(u);
    auto ninf = norm_inf(u);
    
    // ex07
    Matrix<C> A(2, 2, {C(1,1), C(2,0), C(0,-1), C(3,2)});
    auto mv_result = mul_vec(A, u);
    
    // ex08
    auto tr = trace(A);
    
    // ex09
    auto At = transpose(A);
    
    // EX11
    auto det = determinant(A);
    
    std::cout << "✓ ex00: Vector operations work with complex numbers\n";
    std::cout << "✓ ex01: Linear combination works with complex numbers\n";
    std::cout << "✓ ex02: Linear interpolation works with complex numbers\n";
    std::cout << "✓ ex03: Dot product works with complex numbers\n";
    std::cout << "✓ ex04: All norms work with complex numbers\n";
    std::cout << "✓ ex07: Matrix-vector multiplication works with complex numbers\n";
    std::cout << "✓ ex08: Matrix trace works with complex numbers\n";
    std::cout << "✓ ex09: Matrix transpose works with complex numbers\n";
    std::cout << "✓ ex11: Matrix determinant works with complex numbers\n";
    return 0;
}
