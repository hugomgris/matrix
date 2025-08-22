/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 11:54:20 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex09 main

#include "../Vector.hpp"
#include "../Matrix.hpp"

int main(void) {
    Matrix<float> A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    std::cout << "\033[0;33mInitial Test data-----------\033[0m" << std::endl;
    std::cout << "Matrix A:" << std::endl;
    A.print();

    std::cout << "\033[0;33mBasic Transpose test-----------\033[0m" << std::endl;
    Matrix<float> t1 = transpose(A);
    t1.print();

    std::cout << "\033[0;33mRectangular matrix tests-----------\033[0m" << std::endl;
    Matrix<float> rect_2x3(2, 3, {1, 2, 3, 4, 5, 6});
    std::cout << "Original 2×3 matrix:" << std::endl;
    rect_2x3.print();
    
    Matrix<float> rect_t = transpose(rect_2x3);
    std::cout << "Transpose (should be 3×2):" << std::endl;
    rect_t.print();
    
    Matrix<float> rect_3x2(3, 2, {1, 2, 3, 4, 5, 6});
    std::cout << "Original 3×2 matrix:" << std::endl;
    rect_3x2.print();
    
    Matrix<float> rect_3x2_t = transpose(rect_3x2);
    std::cout << "Transpose (should be 2×3):" << std::endl;
    rect_3x2_t.print();

    std::cout << "\033[0;33mDouble transpose test-----------\033[0m" << std::endl;
    Matrix<float> double_t = transpose(transpose(rect_2x3));
    std::cout << "Original matrix:" << std::endl;
    rect_2x3.print();
    std::cout << "Double transpose (should be identical):" << std::endl;
    double_t.print();

    std::cout << "\033[0;33mIdentity matrix test-----------\033[0m" << std::endl;
    Matrix<float> I3(3, 3, {1,0,0, 0,1,0, 0,0,1});
    std::cout << "Identity matrix:" << std::endl;
    I3.print();
    
    Matrix<float> I3_t = transpose(I3);
    std::cout << "Identity transpose (should be same):" << std::endl;
    I3_t.print();

    std::cout << "\033[0;33mZero matrix test-----------\033[0m" << std::endl;
    Matrix<float> Zero(2, 3, {0,0,0,0,0,0});
    std::cout << "Zero matrix (2×3):" << std::endl;
    Zero.print();
    
    Matrix<float> Zero_t = transpose(Zero);
    std::cout << "Zero transpose (3×2):" << std::endl;
    Zero_t.print();

    std::cout << "\033[0;33mSingle element test-----------\033[0m" << std::endl;
    Matrix<float> Single(1, 1, {42});
    std::cout << "Single element matrix:" << std::endl;
    Single.print();
    
    Matrix<float> Single_t = transpose(Single);
    std::cout << "Single element transpose:" << std::endl;
    Single_t.print();

    std::cout << "\033[0;33mRow vector test-----------\033[0m" << std::endl;
    Matrix<float> RowVec(1, 4, {1, 2, 3, 4});
    std::cout << "Row vector (1×4):" << std::endl;
    RowVec.print();
    
    Matrix<float> RowVec_t = transpose(RowVec);
    std::cout << "Row vector transpose (should be 4×1 column):" << std::endl;
    RowVec_t.print();

    std::cout << "\033[0;33mColumn vector test-----------\033[0m" << std::endl;
    Matrix<float> ColVec(4, 1, {5, 6, 7, 8});
    std::cout << "Column vector (4×1):" << std::endl;
    ColVec.print();
    
    Matrix<float> ColVec_t = transpose(ColVec);
    std::cout << "Column vector transpose (should be 1×4 row):" << std::endl;
    ColVec_t.print();

    std::cout << "\033[0;33mSymmetric matrix test-----------\033[0m" << std::endl;
    Matrix<float> Symmetric(3, 3, {1,2,3, 2,4,5, 3,5,6});
    std::cout << "Symmetric matrix:" << std::endl;
    Symmetric.print();
    
    Matrix<float> Sym_t = transpose(Symmetric);
    std::cout << "Symmetric transpose (should be identical):" << std::endl;
    Sym_t.print();

    std::cout << "\033[0;33mManual verification test-----------\033[0m" << std::endl;
    Matrix<float> Manual(2, 3, {1, 2, 3, 4, 5, 6});
    std::cout << "Original matrix:" << std::endl;
    Manual.print();
    std::cout << "Expected transpose:" << std::endl;
    std::cout << "[1, 4]" << std::endl;
    std::cout << "[2, 5]" << std::endl;
    std::cout << "[3, 6]" << std::endl;
    std::cout << "Actual transpose:" << std::endl;
    Matrix<float> Manual_t = transpose(Manual);
    Manual_t.print();

    std::cout << "\033[0;33mTranspose with matrix operations-----------\033[0m" << std::endl;
    Matrix<float> test_mat(3, 3, {1,2,3, 4,5,6, 7,8,9});
    Matrix<float> test_t = transpose(test_mat);
    
    float trace_original = trace(test_mat);
    float trace_transposed = trace(test_t);
    
    std::cout << "trace(A) = " << trace_original << std::endl;
    std::cout << "trace(A^T) = " << trace_transposed << std::endl;
    std::cout << "Should be equal: " << (trace_original == trace_transposed ? "✅" : "❌") << std::endl;

    std::cout << "\033[0;33mWide matrix test-----------\033[0m" << std::endl;
    Matrix<float> Wide(1, 6, {1,2,3,4,5,6});
    std::cout << "Wide matrix (1×6):" << std::endl;
    Wide.print();
    
    Matrix<float> Wide_t = transpose(Wide);
    std::cout << "Wide transpose (should be 6×1):" << std::endl;
    Wide_t.print();

    std::cout << "\033[0;33mTall matrix test-----------\033[0m" << std::endl;
    Matrix<float> Tall(6, 1, {1,2,3,4,5,6});
    std::cout << "Tall matrix (6×1):" << std::endl;
    Tall.print();
    
    Matrix<float> Tall_t = transpose(Tall);
    std::cout << "Tall transpose (should be 1×6):" << std::endl;
    Tall_t.print();

    return 0;
}