/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 14:52:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex13 main

#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    std::cout << "\033[0;33mRank and Rank-Nullity Theorem tests-----------\033[0m" << std::endl;

    std::cout << "Test 1: Identity Matrix (Full Rank)--------" << std::endl;
    Matrix<float> identity(3, 3, {1,0,0, 0,1,0, 0,0,1});
    identity.print();
    verify_rank_nullity_theorem(identity);
    std::cout << "Expected: rank=3, nullity=0\n" << std::endl;
    
    std::cout << "Test 2: Zero Matrix (Rank 0)--------" << std::endl;
    Matrix<float> zero_matrix(3, 3, {0,0,0, 0,0,0, 0,0,0});
    zero_matrix.print();
    verify_rank_nullity_theorem(zero_matrix);
    std::cout << "Expected: rank=0, nullity=3\n" << std::endl;
    
    std::cout << "Test 3: Rank-1 Matrix--------" << std::endl;
    Matrix<float> rank1(3, 3, {1,2,3, 2,4,6, 3,6,9});
    rank1.print();
    verify_rank_nullity_theorem(rank1);
    std::cout << "Expected: rank=1, nullity=2\n" << std::endl;
    
    std::cout << "Test 4: Rank-2 Matrix--------" << std::endl;
    Matrix<float> rank2(3, 3, {1,2,3, 4,5,6, 7,8,9});
    rank2.print();
    verify_rank_nullity_theorem(rank2);
    std::cout << "Expected: rank=2, nullity=1\n" << std::endl;
    
    std::cout << "Test 5: Non-square Matrix (2×4)--------" << std::endl;
    Matrix<float> non_square1(2, 4, {1,2,3,4, 5,6,7,8});
    non_square1.print();
    verify_rank_nullity_theorem(non_square1);
    std::cout << "Expected: rank≤2, nullity≥2\n" << std::endl;

    std::cout << "Test 6: Non-square Matrix (4×2)--------" << std::endl;
    Matrix<float> non_square2(4, 2, {1,2, 3,4, 5,6, 7,8});
    non_square2.print();
    verify_rank_nullity_theorem(non_square2);
    std::cout << "Expected: rank≤2, nullity=0\n" << std::endl;
 
    std::cout << "Test 7: Linearly Dependent Columns--------" << std::endl;
    Matrix<float> dep_cols(3, 4, {1,2,3,5, 2,4,6,10, 1,1,1,2});
    dep_cols.print();
    verify_rank_nullity_theorem(dep_cols);
    std::cout << "Columns 1&2 are multiples, columns 3&4 are multiples\n" << std::endl;

    std::cout << "Test 8: Matrix from ex10--------" << std::endl;
    Matrix<float> ex10_matrix(3, 3, {1,2,3, 2,4,8, 1,3,4});
    ex10_matrix.print();
    verify_rank_nullity_theorem(ex10_matrix);
    std::cout << "From your REF work - should be rank 3\n" << std::endl;

    std::cout << "Test 9: Matrix Requiring Row Swaps--------" << std::endl;
    Matrix<float> swap_matrix(3, 3, {0,1,2, 1,0,3, 2,3,0});
    swap_matrix.print();
    verify_rank_nullity_theorem(swap_matrix);
    std::cout << "Should be full rank despite leading zeros\n" << std::endl;
    
    std::cout << "Test 10: Single Row Matrix--------" << std::endl;
    Matrix<float> single_row(1, 4, {1,2,3,4});
    single_row.print();
    verify_rank_nullity_theorem(single_row);
    std::cout << "Expected: rank=1, nullity=3\n" << std::endl;
    
    std::cout << "Test 11: Single Column Matrix--------" << std::endl;
    Matrix<float> single_col(4, 1, {1, 2, 3, 4});
    single_col.print();
    verify_rank_nullity_theorem(single_col);
    std::cout << "Expected: rank=1, nullity=0\n" << std::endl;
    
    std::cout << "Test 12: Nearly Singular Matrix--------" << std::endl;
    Matrix<float> nearly_singular(2, 2, {1.0f, 2.0f, 1.0000001f, 2.0f});
    nearly_singular.print();
    verify_rank_nullity_theorem(nearly_singular);
    std::cout << "Very small but non-zero determinant\n" << std::endl;
    
    return 0;
}