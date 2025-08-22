/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 12:52:04 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex10 main

#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    std::cout << "\033[0;33mRow-echelon comprehensive test-----------\033[0m" << std::endl;
    
    Matrix<float> A(3, 3, {1, 2, 3, 2, 4, 8, 1, 3, 4});
    std::cout << "Original matrix A:" << std::endl;
    A.print();
    
    Matrix<float> ref_A = row_echelon(A);
    std::cout << "REF of A:" << std::endl;
    ref_A.print();

    Matrix<float> B(3, 3, {1, 2, 3, 0, 0, 0, 4, 5, 6});
    std::cout << "\nMatrix with zero row:" << std::endl;
    B.print();
    
    Matrix<float> ref_B = row_echelon(B);
    std::cout << "REF (zero row should move to bottom):" << std::endl;
    ref_B.print();
    
    Matrix<float> C(3, 3, {1, 2, 3, 0, 1, 4, 0, 0, 1});
    std::cout << "\nAlready in REF:" << std::endl;
    C.print();
    
    Matrix<float> ref_C = row_echelon(C);
    std::cout << "Should remain unchanged:" << std::endl;
    ref_C.print();
    
    return 0;
}