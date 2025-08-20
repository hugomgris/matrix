/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:12:51 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/20 11:56:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <initializer_list>
# include <iostream>
# include <exception>
# include <stdexcept>

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
};

#endif