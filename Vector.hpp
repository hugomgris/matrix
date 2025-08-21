/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:12:51 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/21 17:51:35 by hmunoz-g         ###   ########.fr       */
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

		for (size_t i = 0; i < result.getSize(); ++i) {
			for (size_t j = 0; j < vectors.size(); ++j) {
				result[i] = std::fma(coeffs[j], vectors[j][i], result[i]);
			}
		}
		return (result);
	}

// ex02
/*
Two main ways/formulas to calculate the lerp:
	- A) lerp(start, end, t) = start + t * (end - start)
	- B) lerp(start, end, t) = (1 - t) * start + t * end
*/
	template<typename T>
	Vector<T> lerp(const Vector<T> &u, const Vector<T> &v, const T t) {
		if (u.getSize() != v.getSize()) {
			throw std::invalid_argument("Vectors must have the same size for a linear interpolation");
		}

		std::vector<T> result_data;
		result_data.reserve(u.getSize());
		
		// using A)
		/* Vector<T> diff = sub(v, u);
		diff = scl(diff, t);
		result_data = add(u, diff).getData();
		return (Vector<T>(result_data)); */

		// using B)
		/* Vector<T> wStart = scl(u, 1 - t);
		Vector<T> wEnd = scl(v, t);
		result_data = add(wStart, wEnd).getData();
		return (Vector<T>(result_data)); */

		// using ex01 linear combination
		return linear_combination<T>({u, v}, {T{1} - t, t});
	}

// ex03
	template<typename T>
	T dot(const Vector<T> &u, const Vector<T> &v) {
		if (u.getSize() != v.getSize()) {
			throw std::invalid_argument("Vectors must have the same size for a dot product");
		}
		
		T result = T{};
		// regular way
		/* for (size_t i = 0; i < u.getSize(); ++i) {
			result += u[i] * v[i];
		} */

		// fma way
		for (size_t i = 0; i < u.getSize(); ++i) {
			result = std::fma(u[i], v[i], result);
		}

		return (result);
	}

// ex04
	// norm = distance measure
	template<typename T>
	T norm_1(const Vector<T> &u) {
		T result = T{};

		for (size_t i = 0; i < u.getSize(); ++i) {
			result += std::max(u[i], -u[i]);
		}

		return (result);
	}

	template<typename T>
	T norm(const Vector<T> &u) {
		return (std::pow(dot(u, u), T{0.5}));
	}

	template<typename T>
	T norm_inf(const Vector<T> &u) {
		if (u.getSize() == 0) {
			throw std::invalid_argument("Cannot compute norm of empty vector");
		}
		
		T result = std::max(u[0], -u[0]);
		for (size_t i = 1; i < u.getSize(); ++i) {
			T abs = std::max(u[i], -u[i]);
			result = std::max(result, abs);
		}

		return (result);
	}

// ex05
	template<typename T>
	T angle_cos(const Vector<T> &u, const Vector<T> &v) {
		if (u.getSize() == 0 || v.getSize() == 0) {
			throw std::invalid_argument("Vectors can't be empty for a cosine calculation");
		} else if (u.getSize() != v.getSize()) {
			throw std::invalid_argument("Vectors need to have same size for a cosine calculation");
		}

		T dotProd = dot(u, v);
		T normProd = norm(u) * norm(v);

		if (normProd == T{}) {
     	   throw std::invalid_argument("Cannot compute angle with zero vector");
    	}

		return (dotProd / normProd);
	}

// ex06
	template<typename T>
	Vector<T> cross_product(const Vector<T> &u, const Vector<T> &v) {
		if (u.getSize() != 3 || v.getSize() != 3) {
			throw std::invalid_argument("Cross product can only be defined for 3D vectors");
		}

		T x = (u[1] * v[2]) - (u[2] * v[1]);
		T y = (u[2] * v[0]) - (u[0] * v[2]);
		T z = (u[0] * v[1]) - (u[1] * v[0]);

		return (Vector<T>({x, y, z}));
	}
#endif