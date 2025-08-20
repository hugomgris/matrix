/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:30:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/20 11:55:37 by hmunoz-g         ###   ########.fr       */
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

#endif