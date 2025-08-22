/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:30:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/22 17:43:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>
# include <initializer_list>
# include <utility>
# include <iostream>
# include <exception>
# include <stdexcept>
# include <cstdint>
# include <cmath>

template<typename T> class Vector;

template<typename T = float>
class Matrix {
	private:
		size_t _rows, _cols;
		std::vector<T> _data;

	public:
		// Constructors and Destructor (default)
		Matrix(size_t rows, size_t cols): _rows(rows), _cols(cols), _data(rows * cols, T{}) {}

		Matrix(size_t rows, size_t cols, std::vector<T> data): _rows(rows), _cols(cols), _data(data) {
			if (rows * cols != data.size()) {
				throw std::invalid_argument("Matrix dimensions don't match data size");
			}
		}

		Matrix(std::initializer_list<std::initializer_list<T>> rows) {
			// Empty check
			if (rows.size() == 0) {
				_rows = 0;
				_cols = 0;
				_data = std::vector<T>(); 
				return;
			}

			_rows = rows.size();
			_cols = rows.begin()->size();
			
			// Validation loop
			auto it = rows.begin();
			for (size_t i = 0; i < rows.size(); ++i, ++it) {
				if (it->size() != _cols) { 
					throw std::runtime_error("Invalid matrix dimensions: rows have inconsistent column counts");
				}
			}

			// Building loop
			it = rows.begin();
			for (size_t i = 0; i < rows.size(); ++i, it++) {
				auto it2 = it->begin();
				for (size_t j = 0; j < _cols; j++, it2++) {
					_data.push_back(*it2);
				}
			}
		}

		Matrix(const Matrix &other) : _rows(other._rows), _cols(other._cols), _data(other._data) {}

		~Matrix() = default;

		// Getters
		const std::vector<T> &getData() const { return (_data); }

		size_t getRows() const { return (_rows); }

		size_t getCols() const { return (_cols); }

		std::pair<size_t, size_t> getShape() const { return (std::pair<size_t, size_t>(_rows, _cols)); }

		size_t getPivot(size_t current_row, size_t current_col) const {
			for (size_t i = current_row; i < getRows(); i++) {
				if (std::abs((*this)(i, current_col)) > 1e-10) {
					return i; 
				}
			}
			return SIZE_MAX;
		}	

		// Methods
		void print() const {
			for (size_t i = 0; i < _rows; ++i) {
				std:: cout << "[";
				for (size_t j = 0; j < _cols; ++j) {
					std::cout << _data[i * _cols + j];
					if (j < _cols - 1) { std::cout << ", "; }
				}
				std::cout << "]" << std::endl;
			}
		}

		bool isSquare() const { return (_rows == _cols); }

		Vector<T> toVector() const {
			return (Vector<T>(_data));
		}

		void swap_rows(size_t row_1, size_t row_2) {
			if (row_1 == row_2) return;
			
			for (size_t j = 0; j < getCols(); j++) {
				T temp = (*this)(row_1, j);
				(*this)(row_1, j) = (*this)(row_2, j);
				(*this)(row_2, j) = temp;
			}
		}

		void eliminate_below(size_t pivot_row, size_t pivot_col) {
			T pivot = (*this)(pivot_row, pivot_col);
			
			if (std::abs(pivot) < 1e-10) return;
			
			for (size_t i = pivot_row + 1; i < getRows(); ++i) {
				T element = (*this)(i, pivot_col);
				
				if (std::abs(element) > 1e-10) {
					T factor = element / pivot;
					
					for (size_t j = pivot_col; j < getCols(); ++j) {
						(*this)(i, j) = (*this)(i, j) - factor * (*this)(pivot_row, j);
					}
				}
			}
		}

		// Operator overloads
		T &operator[](size_t index) { return (_data[index]); }

		const T &operator[](size_t index) const { return (_data[index]); }

		T &operator()(size_t row, size_t col) { 
			if (row >= _rows || col >= _cols) {
				throw std::out_of_range("Matrix index out of bounds");
			}
			return _data[row * _cols + col]; 
		}

		const T &operator()(size_t row, size_t col) const {
			if (row >= _rows || col >= _cols) {
				throw std::out_of_range("Matrix index out of bounds");
			}
			return _data[row * _cols + col];
		}

		Matrix &operator=(const Matrix &other) {
			if (this != &other)
			{
				_data = other._data;
				_rows = other._rows;
				_cols = other._cols;
			}
			return (*this);
		}
};

// ex07
template<typename T>
Vector<T> mul_vec(const Matrix<T> &A, const Vector<T> &u) {
	if (A.getCols() != u.getSize()) {
		throw std::invalid_argument("Matrix columns must match vector size");
	}

	std::vector<T> result_data;
	result_data.reserve(A.getRows());

	// Version with dot product
	/* for (size_t i = 0; i < A.getRows(); ++i) {
		std::vector<T> matrixElements;
		for (size_t j = 0; j < A.getCols(); ++j) {
			matrixElements.push_back(A(i, j));
		}
		result_data.push_back(dot(Vector<T>(matrixElements), u));
	} */

	// Version with fma
	for (size_t i = 0; i < A.getRows(); ++i) {
        T sum = T{};
        for (size_t j = 0; j < A.getCols(); ++j) {
            sum = std::fma(A(i, j), u[j], sum);
        }
        result_data.push_back(sum);
    }

	return (Vector<T>(result_data));
}

template<typename T>
Matrix<T> mul_mat(const Matrix<T> &A, const Matrix<T> &B) {
	// A is m×n, B must be n×p
	if (A.getCols() != B.getRows()) {
		throw std::invalid_argument("Matrix A columns must match Matrix B rows");
	}

	//Matrix(size_t rows, size_t cols, std::vector<T> data)
	size_t result_rows = A.getRows();
	size_t result_cols = B.getCols();
	size_t n = A.getCols();

	Matrix<T> result(result_rows, result_cols);

	// version with dot product
	/* for (size_t i = 0; i < A.getRows(); ++i) {
		for (size_t j = 0; j < B.getCols(); ++j) {
			std::vector<T> A_data;
			std::vector<T> B_data;
			for (size_t k = 0; k < n; ++k){
				A_data.push_back(A(i, k));
				B_data.push_back(B(k, j));
			}
			result(i, j) = dot(Vector<T>(A_data), Vector<T>(B_data));
		}
	} */

	// version with fma
	for (size_t i = 0; i < result_rows; ++i) {
        for (size_t j = 0; j < result_cols; ++j) {
            T sum = T{};
            for (size_t k = 0; k < n; ++k) {
                sum = std::fma(A(i, k), B(k, j), sum);
            }
            result(i, j) = sum;
        }
    }

	return (result);
}

// ex08
template<typename T>
T trace(const Matrix<T> &A) {
	if (!A.isSquare()) {
		throw std::invalid_argument("Trace can only be computed for square matrices (nRows = nCols)");
	}

	T sum = T{};
	for (size_t i = 0; i < A.getRows(); ++i) {
		sum += A(i, i);
	}

	return (sum);
}

// ex09
template<typename T>
Matrix<T> transpose(const Matrix<T> &A) {
	size_t rows = A.getRows();
	size_t cols = A.getCols();

	Matrix<T> transposed(cols, rows);

	for (size_t i = 0; i < A.getRows(); ++i) {
		for (size_t j = 0; j < A.getCols(); ++j) {
			transposed(j, i) = A(i, j);
		}
	}

	return (transposed);
}

// ex10
template<typename T>
Matrix<T> row_echelon(const Matrix<T> &A) {
    Matrix<T> result = A;
    
    size_t current_row = 0;
    
    for (size_t col = 0; col < result.getCols() && current_row < result.getRows(); ++col) {
        size_t pivot_row = result.getPivot(current_row, col);
        
        if (pivot_row == SIZE_MAX) {
            continue;
        }
        
        if (pivot_row != current_row) {
            result.swap_rows(current_row, pivot_row);
        }
        
        result.eliminate_below(current_row, col);
        current_row++;
    }
    
    return result;
}

// This is used by the next exercise. Same function but with swap tracking to know the determinant sign for complex matrices
template<typename T>
std::pair<Matrix<T>, int> row_echelon_with_swaps(const Matrix<T> &A) {
    Matrix<T> result = A;
    int swap_count = 0;
    
    size_t current_row = 0;
    
    for (size_t col = 0; col < result.getCols() && current_row < result.getRows(); ++col) {
        size_t pivot_row = result.getPivot(current_row, col);
        
        if (pivot_row == SIZE_MAX) {
            continue;
        }
        
        if (pivot_row != current_row) {
            result.swap_rows(current_row, pivot_row);
            swap_count++;
        }
        
        result.eliminate_below(current_row, col);
        current_row++;
    }
    
    return std::make_pair(result, swap_count);
}

// ex11
template<typename T>
Matrix<T> getMinor(const Matrix<T> &A, size_t remove_row, size_t remove_col) {
    size_t rows = A.getRows();
    size_t cols = A.getCols();
    
    Matrix<T> minor(rows - 1, cols - 1);
    
    size_t minor_row = 0;
    for (size_t i = 0; i < rows; ++i) {
        if (i == remove_row) continue;
        
        size_t minor_col = 0;
        for (size_t j = 0; j < cols; ++j) {
            if (j == remove_col) continue;
            
            minor(minor_row, minor_col) = A(i, j);
            minor_col++;
        }
        minor_row++;
    }
    
    return minor;
}

template<typename T>
T determinant(const Matrix<T> &A) {
	if (!A.isSquare()) {
        throw std::invalid_argument("Determinant only defined for square matrices");
    }

	size_t n = A.getRows();
    
    if (n == 1) {
        return A(0, 0);
    }

	if (n == 2) {
        return ((A(0,0) * A(1,1)) - (A(0,1) * A(1,0)));
    }

	T det = T{};
    for (size_t j = 0; j < n; ++j) {
        Matrix<T> minor = getMinor(A, 0, j);
        T cofactor = ((j % 2 == 0) ? 1 : -1) * determinant(minor);
        det += A(0, j) * cofactor;
    }
    return det;
}

template<typename T>
T determinant_efficient(const Matrix<T> &A) {
    if (!A.isSquare()) {
        throw std::invalid_argument("Determinant only defined for square matrices");
    }
    
    auto [ref, swap_count] = row_echelon_with_swaps(A);
    
    T det = T{1};
    for (size_t i = 0; i < A.getRows(); ++i) {
        det *= ref(i, i);
    }
    
    if (swap_count % 2 == 1) {
        det = -det;
    }
    
    return det;
}

// ex12
// Gauss-Jordan strategy
// Add this function to Matrix.hpp (outside the class):
template<typename T>
size_t find_pivot_row(const Matrix<T> &matrix, size_t start_row, size_t col) {
    for (size_t i = start_row; i < matrix.getRows(); ++i) {
        if (std::abs(matrix(i, col)) > 1e-10) {
            return i;
        }
    }
    return SIZE_MAX;
}

template<typename T>
void gauss_jordan_elimination(Matrix<T> &augmented) {
    size_t n = augmented.getRows();
    
    for (size_t col = 0; col < n; ++col) {
        size_t pivot_row = find_pivot_row(augmented, col, col);
        if (pivot_row == SIZE_MAX) {
            throw std::runtime_error("Matrix is singular");
        }
        
        if (pivot_row != col) {
            augmented.swap_rows(col, pivot_row);
        }
        
        T pivot = augmented(col, col);
        for (size_t j = 0; j < augmented.getCols(); ++j) {
            augmented(col, j) /= pivot;
        }
        
        for (size_t i = 0; i < n; ++i) {
            if (i != col && std::abs(augmented(i, col)) > 1e-10) {
                T factor = augmented(i, col);
                for (size_t j = 0; j < augmented.getCols(); ++j) {
                    augmented(i, j) -= factor * augmented(col, j);
                }
            }
        }
    }
}

template<typename T>
Matrix<T> inverse(const Matrix<T> &A) {
	if (!A.isSquare()) {
		throw std::invalid_argument("Inverse only defined for square matrices");
	}

	if (std::abs(determinant(A)) < 1e-10) {
		throw std::runtime_error("Matrix is singular (non-invertible)");
	}

	size_t n = A.getRows();
	Matrix<T> augmented(n, 2 * n);

	for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            augmented(i, j) = A(i, j);
        }
    }

	for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            augmented(i, j + n) = (i == j) ? T{1} : T{0};
        }
    }

	gauss_jordan_elimination(augmented);

	Matrix<T> result(n, n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            result(i, j) = augmented(i, j + n);
        }
    }
    
    return result;
}

// ex13
template<typename T>
size_t rank(const Matrix<T> &A) {
    Matrix<T> ref = row_echelon(A);
    
    size_t rank_count = 0;
    for (size_t i = 0; i < ref.getRows(); ++i) {
        bool is_zero_row = true;
        for (size_t j = 0; j < ref.getCols(); ++j) {
            if (std::abs(ref(i, j)) > 1e-10) {
                is_zero_row = false;
                break;
            }
        }
        if (!is_zero_row) rank_count++;
    }
    
    return rank_count;
}

template<typename T>
size_t nullity(const Matrix<T> &A) {
    return A.getCols() - rank(A);
}

template<typename T>
void verify_rank_nullity_theorem(const Matrix<T> &A) {
    size_t r = rank(A);
    size_t n = nullity(A);
    size_t cols = A.getCols();
    
    std::cout << "Matrix: " << A.getRows() << "×" << cols << std::endl;
    std::cout << "Rank: " << r << std::endl;
    std::cout << "Nullity: " << n << std::endl;
    std::cout << "Sum: " << (r + n) << std::endl;
    std::cout << "Columns: " << cols << std::endl;
    std::cout << "Theorem verified: " << (r + n == cols ? "TRUE" : "FALSE") << std::endl;
}

// ex14
template<typename T>
Matrix<T> projection(T fov, T ratio, T near, T far) {
    T fov_rad = fov * M_PI / 180.0;
    
    T tan_half_fov = std::tan(fov_rad / 2.0);
    
    Matrix<T> proj(4, 4);
    
    proj(0, 0) = 1.0 / (ratio * tan_half_fov);
    proj(1, 1) = 1.0 / tan_half_fov;
    proj(2, 2) = -(far + near) / (far - near);
    proj(2, 3) = -(2.0 * far * near) / (far - near);
    proj(3, 2) = -1.0;
	
    return proj;
}
#endif