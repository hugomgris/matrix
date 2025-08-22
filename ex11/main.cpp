/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 13:27:10 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex11 main

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include <chrono>

int main() {
    std::cout << "\033[0;33mDeterminant tests-----------\033[0m" << std::endl;
    
    Matrix<float> A2(2, 2, {1, 2, 3, 4});
    std::cout << "2×2 matrix:" << std::endl;
    A2.print();
    std::cout << "det (cofactor) = " << determinant(A2) << " (should be -2)" << std::endl;
    std::cout << "det (efficient) = " << determinant_efficient(A2) << " (should be -2)" << std::endl;
    
    Matrix<float> A3(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    std::cout << "\n3×3 singular matrix:" << std::endl;
    A3.print();
    std::cout << "det (cofactor) = " << determinant(A3) << " (should be 0)" << std::endl;
    std::cout << "det (efficient) = " << determinant_efficient(A3) << " (should be 0)" << std::endl;
    
    Matrix<float> I(3, 3, {1,0,0, 0,1,0, 0,0,1});
    std::cout << "\nIdentity matrix:" << std::endl;
    I.print();
    std::cout << "det (cofactor) = " << determinant(I) << " (should be 1)" << std::endl;
    std::cout << "det (efficient) = " << determinant_efficient(I) << " (should be 1)" << std::endl;
    
    Matrix<float> S(2, 2, {2, 0, 0, 3});
    std::cout << "\nScaling matrix:" << std::endl;
    S.print();
    std::cout << "det (cofactor) = " << determinant(S) << " (should be 6)" << std::endl;
    std::cout << "det (efficient) = " << determinant_efficient(S) << " (should be 6)" << std::endl;
    
    Matrix<float> swap_test(3, 3, {0, 1, 2, 1, 0, 3, 2, 3, 0});
    std::cout << "\nMatrix requiring row swaps:" << std::endl;
    swap_test.print();
    std::cout << "det (cofactor) = " << determinant(swap_test) << std::endl;
    std::cout << "det (efficient) = " << determinant_efficient(swap_test) << std::endl;
    std::cout << "Should be equal!" << std::endl;
    
    Matrix<float> upper(3, 3, {2, 1, 3, 0, 4, 2, 0, 0, 5});
    std::cout << "\nUpper triangular matrix:" << std::endl;
    upper.print();
    std::cout << "det (cofactor) = " << determinant(upper) << std::endl;
    std::cout << "det (efficient) = " << determinant_efficient(upper) << std::endl;
    std::cout << "Should be 2×4×5 = 40" << std::endl;
    
    Matrix<float> large(4, 4, {1,2,3,4, 5,6,7,8, 9,10,12,13, 14,15,16,17});
    std::cout << "\n4×4 matrix performance test:" << std::endl;
    large.print();
    
    auto start_cofactor = std::chrono::high_resolution_clock::now();
    float det_cofactor = determinant(large);
    auto end_cofactor = std::chrono::high_resolution_clock::now();
    
    auto start_efficient = std::chrono::high_resolution_clock::now();
    float det_efficient = determinant_efficient(large);
    auto end_efficient = std::chrono::high_resolution_clock::now();
    
    std::cout << "det (cofactor) = " << det_cofactor << std::endl;
    std::cout << "det (efficient) = " << det_efficient << std::endl;
    
    auto duration_cofactor = std::chrono::duration_cast<std::chrono::microseconds>(end_cofactor - start_cofactor);
    auto duration_efficient = std::chrono::duration_cast<std::chrono::microseconds>(end_efficient - start_efficient);
    
    std::cout << "Cofactor time: " << duration_cofactor.count() << " µs" << std::endl;
    std::cout << "Efficient time: " << duration_efficient.count() << " µs" << std::endl;
    
    return 0;
}