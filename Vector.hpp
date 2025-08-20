/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:12:51 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/20 17:18:32 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <initializer_list>
# include <iostream>
# include <exception>
# include <stdexcept>
# include <cmath>

template <typename T> class Matrix;

template<typename T = float>
class Vector {
	private:
		std::vector<T> _data;
	
	public:
		// Constructors and destructor (default)
		Vector() : _data() {}
		
		Vector(std::initializer_list<T> values): _data(values) {}

		Vector(const std::vector<T>& data) : _data(data) {}
		
		Vector(const Vector &other): _data(other._data) {}

		Vector(size_t size, const T &value = T{}): _data(size, value) {}

		~Vector() = default;

		// Getters
		size_t getSize() const { return (_data.size()); }
		const std::vector<T> &getData() const { return _data; }

		// Methods
		void print() const {
			std::cout << "[";
			for (size_t i = 0; i < _data.size(); ++i) {
				std::cout << _data[i];
				if (i < _data.size() - 1) std::cout << ", ";
			}
			std::cout << "]" << std::endl;
		}
		
		// Matrix converter
		Matrix<T> toMatrix() const {
			return Matrix<T>(_data.size(), 1, _data);
		}

		// Operator overloads
		T &operator[](size_t index) {
			if (index >= _data.size()) {
				throw std::out_of_range("Vector index out of bounds");
			}

			return (_data[index]);
		}

		const T &operator[](size_t index) const {
			if (index >= _data.size()) {
				throw std::out_of_range("Vector index out of bounds");
			}

			return (_data[index]);
		}

		Vector &operator=(const Vector &other) {
			if (this != &other) {
				_data = other._data;
			}
			
			return (*this);
		}

		Vector operator+(const Vector &other) {
			return (add(*this, other));
		}

		Vector operator-(const Vector &other) {
			return (sub(*this, other));
		}

		Vector operator*(const T &scalar) {
			return (scl(*this, scalar));
		}
};

// ex00
	template<typename T>
	Vector<T> add(const Vector<T> &u, const Vector<T> &v) {
		if (u.getSize() != v.getSize()) {
			throw std::invalid_argument("Vectors must have the same size for addition");
		}

		std::vector<T> result;
		result.reserve(u.getSize());

		for (size_t i = 0; i < u.getSize(); ++i) {
			result.push_back(u[i] + v[i]);
		}

		return (Vector<T>(result));
	}

	template<typename T>
	Vector<T> sub(const Vector<T> &u, const Vector<T> &v) {
		if (u.getSize() != v.getSize()) {
			throw std::invalid_argument("Vectors must have the same size for substraction");
		}

		std::vector<T> result;
		result.reserve(u.getSize());

		for (size_t i = 0; i < u.getSize(); ++i) {
			result.push_back(u[i] - v[i]);
		}

		return (Vector<T>(result));
	}

	template<typename T>
	Vector<T> scl(const Vector<T> &u, const T scalar) {
		std::vector<T> result;
		result.reserve(u.getSize());

		for (size_t i = 0; i < u.getSize(); ++i) {
			result.push_back(u[i] * scalar);
		}

		return (Vector<T>(result));
	}

// ex01
	template<typename T>
	Vector<T> linear_combination(const std::vector<Vector<T>> &vectors, const std::vector<T> &coeffs) {
		if (vectors.size() != coeffs.size()) {
			throw std::invalid_argument("Amount of vectors and coefficients must match");
		}

		if (vectors.empty()) {
        	throw std::invalid_argument("Cannot compute linear combination of empty vector list");
    	}

		Vector<T> result(vectors[0].getSize(), T{});

		// Version with no fma (using ex00 functions)
		/* for (size_t i = 0; i < vectors.size(); ++i) {
			result = add (result, scl(vectors[i], coeffs[i]));
		} */

		// Version with fma (Fused Multiply-Add)
		for (size_t i = 0; i < result.getSize(); ++i) {
			for (size_t j = 0; j < vectors.size(); ++j) {
				result[i] = std::fma(coeffs[j], vectors[j][i], result[i]);
			}
		}
		return (result);
	}

#endif