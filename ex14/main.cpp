/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:30:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 18:28:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex14 main

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include <fstream>
#include <iomanip>

void validateProjectionMatrix(const Matrix<float>& proj, float fov, float ratio) {
    std::cout << "=== Projection Matrix Validation ===" << std::endl;
    
    float expected_y_scale = 1.0f / std::tan((fov * M_PI / 180.0f) / 2.0f);
    float expected_x_scale = expected_y_scale / ratio;
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Expected X scale: " << expected_x_scale << ", Got: " << proj(0,0) << std::endl;
    std::cout << "Expected Y scale: " << expected_y_scale << ", Got: " << proj(1,1) << std::endl;
    std::cout << "Z component (2,2): " << proj(2,2) << " (should be negative)" << std::endl;
    std::cout << "W component (3,2): " << proj(3,2) << " (should be -1)" << std::endl;
    
    if (std::abs(proj(3,2) + 1.0f) < 1e-6) {
        std::cout << "✓ Perspective division correctly set up" << std::endl;
    } else {
        std::cout << "✗ Perspective division incorrect" << std::endl;
    }
    
    std::cout << "=================================" << std::endl;
}

int main() {
    std::cout << "\033[0;33mProjection Matrix Tests-----------\033[0m" << std::endl;

    std::cout << "Test 1: Standard Perspective Projection--------" << std::endl;
    auto proj1 = projection<float>(60.0f, 16.0f/9.0f, 0.1f, 100.0f);
    std::cout << "FOV: 60°, Aspect: 16:9, Near: 0.1, Far: 100" << std::endl;
    proj1.print();
    validateProjectionMatrix(proj1, 60.0f, 16.0f/9.0f);
    std::cout << std::endl;
    
    std::cout << "Test 2: Square Viewport--------" << std::endl;
    auto proj2 = projection<float>(45.0f, 1.0f, 1.0f, 10.0f);
    std::cout << "FOV: 45°, Aspect: 1:1, Near: 1, Far: 10" << std::endl;
    proj2.print();
    validateProjectionMatrix(proj2, 45.0f, 1.0f);
    std::cout << std::endl;

    std::cout << "Creating projection matrix file for display program..." << std::endl;
    auto display_proj = projection<float>(60.0f, 16.0f/9.0f, 0.1f, 100.0f);
    
    std::ofstream proj_file("proj");
    if (proj_file.is_open()) {
        proj_file << std::fixed << std::setprecision(6);
        for (size_t i = 0; i < 4; ++i) {
            for (size_t j = 0; j < 4; ++j) {
                proj_file << display_proj(i, j);
                if (j < 3) proj_file << ", ";
            }
            proj_file << std::endl;
        }
        proj_file.close();
        std::cout << "Projection matrix saved to 'proj' file" << std::endl;
        
        std::ifstream verify("proj");
        if (verify.is_open()) {
            std::cout << "File contents:" << std::endl;
            std::string line;
            while (std::getline(verify, line)) {
                std::cout << line << std::endl;
            }
            verify.close();
        }
    } else {
        std::cout << "Error: Could not create proj file" << std::endl;
    }

    return 0;
}