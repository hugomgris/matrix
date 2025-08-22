/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 14:29:02 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex12 main

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include <chrono>

int main() {
    std::cout << "\033[0;33mMatrix Inverse tests-----------\033[0m" << std::endl;
    
    Matrix<float> A2(2, 2, {1, 2, 3, 4});
    std::cout << "Original 2×2 matrix:" << std::endl;
    A2.print();
    
    try {
        Matrix<float> A2_inv = inverse(A2);
        std::cout << "Inverse:" << std::endl;
        A2_inv.print();
        
        Matrix<float> product = mul_mat(A2, A2_inv);
        std::cout << "A × A⁻¹ (should be identity):" << std::endl;
        product.print();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    Matrix<float> I(3, 3, {1,0,0, 0,1,0, 0,0,1});
    std::cout << "\nIdentity matrix:" << std::endl;
    I.print();
    Matrix<float> I_inv = inverse(I);
    std::cout << "Inverse of identity:" << std::endl;
    I_inv.print();
    
    Matrix<float> singular(2, 2, {1, 2, 2, 4});
    std::cout << "\nSingular matrix (should fail):" << std::endl;
    singular.print();
    try {
        Matrix<float> sing_inv = inverse(singular);
    } catch (const std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }
    
    Matrix<float> A3(3, 3, {2, 1, 1, 1, 2, 1, 1, 1, 2});
    std::cout << "\n3×3 matrix:" << std::endl;
    A3.print();
    Matrix<float> A3_inv = inverse(A3);
    std::cout << "Inverse:" << std::endl;
    A3_inv.print();
    
    Matrix<float> product3 = mul_mat(A3, A3_inv);
    std::cout << "A × A⁻¹ (should be identity):" << std::endl;
    product3.print();
    
    return 0;
}