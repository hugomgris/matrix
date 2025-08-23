/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:00:00 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/08/23 10:00:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_HPP
# define COMPLEX_HPP

# include <cmath>
# include <iostream>
# include <ostream>

template<typename T = float>
class Complex {
	public:
		using value_type = T;
		
	private:
		T _real;
		T _imag;

	public:
		// Constructors & destructor
		Complex() : _real(T{}), _imag(T{}) {}
		
		Complex(T real) : _real(real), _imag(T{}) {}
		
		Complex(T real, T imag) : _real(real), _imag(imag) {}
		
		Complex(const Complex &other) : _real(other._real), _imag(other._imag) {}
		
		~Complex() = default;

		// Getters
		T getReal() const { return _real; }
		T getImag() const { return _imag; }

		// Setters
		void setReal(T real) { _real = real; }
		void setImag(T imag) { _imag = imag; }

		// Operator overloads
		Complex &operator=(const Complex &other) {
			if (this != &other) {
				_real = other._real;
				_imag = other._imag;
			}
			return *this;
		}

		Complex operator+(const Complex &other) const {
			return Complex(_real + other._real, _imag + other._imag);
		}

		Complex operator-(const Complex &other) const {
			return Complex(_real - other._real, _imag - other._imag);
		}

		Complex operator*(const Complex &other) const {
			// (a + bi)(c + di) = (ac - bd) + (ad + bc)i
			return Complex(
				_real * other._real - _imag * other._imag,
				_real * other._imag + _imag * other._real
			);
		}

		Complex operator*(const T &scalar) const {
			return Complex(_real * scalar, _imag * scalar);
		}

		Complex operator/(const Complex &other) const {
			// (a + bi)/(c + di) = [(a + bi)(c - di)] / (c² + d²)
			T denominator = other._real * other._real + other._imag * other._imag;
			if (denominator == T{}) {
				throw std::runtime_error("Division by zero complex number");
			}
			return Complex(
				(_real * other._real + _imag * other._imag) / denominator,
				(_imag * other._real - _real * other._imag) / denominator
			);
		}

		Complex operator/(const T &scalar) const {
			if (scalar == T{}) {
				throw std::runtime_error("Division by zero");
			}
			return Complex(_real / scalar, _imag / scalar);
		}

		// Unary operators
		Complex operator-() const {
			return Complex(-_real, -_imag);
		}

		Complex operator+() const {
			return *this;
		}

		// Compound operators
		Complex &operator+=(const Complex &other) {
			_real += other._real;
			_imag += other._imag;
			return *this;
		}

		Complex &operator-=(const Complex &other) {
			_real -= other._real;
			_imag -= other._imag;
			return *this;
		}

		Complex &operator*=(const Complex &other) {
			T temp_real = _real * other._real - _imag * other._imag;
			_imag = _real * other._imag + _imag * other._real;
			_real = temp_real;
			return *this;
		}

		Complex &operator*=(const T &scalar) {
			_real *= scalar;
			_imag *= scalar;
			return *this;
		}

		Complex &operator/=(const Complex &other) {
			*this = *this / other;
			return *this;
		}

		Complex &operator/=(const T &scalar) {
			if (scalar == T{}) {
				throw std::runtime_error("Division by zero");
			}
			_real /= scalar;
			_imag /= scalar;
			return *this;
		}

		// Comparison operators
		bool operator==(const Complex &other) const {
			return (_real == other._real && _imag == other._imag);
		}

		bool operator!=(const Complex &other) const {
			return !(*this == other);
		}

		// Mathematical functions
		T magnitude() const {
			return std::sqrt(_real * _real + _imag * _imag);
		}

		T magnitudeSquared() const {
			return _real * _real + _imag * _imag;
		}

		Complex conjugate() const {
			return Complex(_real, -_imag);
		}

		T argument() const {
			return std::atan2(_imag, _real);
		}

		// Static methods for common complex numbers
		static Complex zero() { return Complex(T{}, T{}); }
		static Complex one() { return Complex(T{1}, T{}); }
		static Complex i() { return Complex(T{}, T{1}); }

		// Stream operators
		friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
			if (c._imag >= T{}) {
				os << c._real << " + " << c._imag << "i";
			} else {
				os << c._real << " - " << (-c._imag) << "i";
			}
			return os;
		}
};

// Global operator for scalar operations
template<typename T>
Complex<T> operator*(const T &scalar, const Complex<T> &c) {
	return c * scalar;
}

// Mathematical functions that work with Complex numbers
template<typename T>
Complex<T> abs(const Complex<T> &c) {
	return Complex<T>(c.magnitude());
}

// Magnitude comparison for complex numbers (needed for norm inf)
template<typename T>
T max(const Complex<T> &a, const Complex<T> &b) {
	return (a.magnitude() > b.magnitude()) ? a.magnitude() : b.magnitude();
}

// fma equivalent for complex numbers
template<typename T>
Complex<T> std_fma(const Complex<T> &a, const Complex<T> &b, const Complex<T> &c) {
	return a * b + c;
}

#endif
