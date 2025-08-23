# <h1 align="center">MATRIX</h1>

<p align="center">
   <b>A comprehensive linear algebra library implementation in C++, featuring template-based vector and matrix operations, complex number support, and advanced mathematical algorithms for computational mathematics and scientific computing applications.</b><br>
</p>

---

<p align="center">
    <img alt="C++" src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
    <img alt="Math" src="https://img.shields.io/badge/Mathematics-FF6B6B?style=for-the-badge&logo=mathworks&logoColor=white" />
    <img alt="Linear Algebra" src="https://img.shields.io/badge/Linear%20Algebra-4ECDC4?style=for-the-badge" />
</p>
<p align="center">
    <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/hugomgris/matrix?color=lightblue" />
    <img alt="Exercise Count" src="https://img.shields.io/badge/Exercises-15-brightgreen" />
    <img alt="Standard" src="https://img.shields.io/badge/C++-17-blue" />
</p>

## Table of Contents

- [General Description](#general-description)
- [Mathematical Foundation](#mathematical-foundation)
- [Build & Execution Instructions](#build--execution-instructions)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Example Usage](#example-usage)
- [Project Structure](#project-structure)
- [Exercise Breakdown](#exercise-breakdown)
  - [Foundation Operations (ex00-ex02)](#foundation-operations-ex00-ex02)
  - [Vector Metrics and Properties (ex03-ex06)](#vector-metrics-and-properties-ex03-ex06)
  - [Matrix Operations (ex07-ex09)](#matrix-operations-ex07-ex09)
  - [Advanced Matrix Algorithms (ex10-ex12)](#advanced-matrix-algorithms-ex10-ex12)
  - [Matrix Analysis (ex13-ex14)](#matrix-analysis-ex13-ex14)
  - [Complex Vector Spaces (ex15)](#complex-vector-spaces-ex15)
- [Core Components](#core-components)
- [Implementation Details](#implementation-details)
- [Performance Considerations](#performance-considerations)
- [Applications](#applications)
- [Theoretical Background](#theoretical-background)
- [Advanced Features](#advanced-features)
- [Troubleshooting](#troubleshooting)
- [Documentation](#documentation)
- [License](#license)

---

## General Description

The Matrix project is a comprehensive implementation of fundamental linear algebra operations and algorithms in C++. Built with modern C++17 features and template programming, it provides a robust foundation for mathematical computing, supporting both real and complex number systems.

The implementation spans 15 progressive exercises, each building upon previous concepts to create a complete linear algebra library suitable for scientific computing, computer graphics, machine learning, and engineering applications.

## Mathematical Foundation

Linear algebra forms the backbone of modern computational mathematics. This implementation covers:

- **Vector Spaces**: Mathematical structures supporting addition and scalar multiplication
- **Linear Transformations**: Functions preserving vector space operations
- **Matrix Theory**: Rectangular arrays of numbers with defined operations
- **Complex Analysis**: Extension to complex number fields
- **Numerical Methods**: Computational approaches to mathematical problems

```
Vector Space Axioms:
∀ u, v, w ∈ V and ∀ a, b ∈ ℝ (or ℂ):
1. u + v ∈ V                    (Closure under addition)
2. u + v = v + u                (Commutativity)
3. (u + v) + w = u + (v + w)    (Associativity)
4. ∃ 0 ∈ V : u + 0 = u         (Additive identity)
5. ∀ u ∃ (-u) : u + (-u) = 0   (Additive inverse)
6. a·u ∈ V                      (Closure under scalar multiplication)
7. a(bu) = (ab)u                (Scalar associativity)
8. 1·u = u                      (Scalar identity)
9. a(u + v) = au + av           (Distributivity)
10. (a + b)u = au + bu          (Distributivity)
```

## Build & Execution Instructions

### Prerequisites

- **Compiler**: g++ or clang++ with C++17 support
- **Make**: GNU Make utility
- **System**: Linux/macOS/Windows with WSL

### Compilation

Each exercise can be compiled independently:

```bash
# Compile specific exercise
cd ex00
make

# Run the exercise
./ex00
```

For complex number support:
```bash
cd ex15
make
./ex15
```

### Example Usage

```cpp
#include "Vector.hpp"
#include "Matrix.hpp"

int main() {
    // Vector operations
    Vector<float> u = {1.0f, 2.0f, 3.0f};
    Vector<float> v = {4.0f, 5.0f, 6.0f};
    
    auto sum = add(u, v);
    float dot_product = dot(u, v);
    float magnitude = norm(u);
    
    // Matrix operations
    Matrix<float> A(2, 2, {1, 2, 3, 4});
    Vector<float> result = mul_vec(A, u);
    float determinant_value = determinant(A);
    
    return 0;
}
```

## Project Structure

```
matrix/
├── Vector.hpp              # Vector class and operations
├── Matrix.hpp              # Matrix class and operations  
├── Complex.hpp             # Complex number implementation
├── ex00/                   # Basic vector operations
├── ex01/                   # Linear combinations
├── ex02/                   # Linear interpolation
├── ex03/                   # Dot product
├── ex04/                   # Vector norms
├── ex05/                   # Angle and cosine
├── ex06/                   # Cross product
├── ex07/                   # Matrix multiplication
├── ex08/                   # Matrix trace
├── ex09/                   # Matrix transpose
├── ex10/                   # Row echelon form
├── ex11/                   # Matrix determinant
├── ex12/                   # Matrix inverse
├── ex13/                   # Rank and nullity
├── ex14/                   # Projection matrix
├── ex15/                   # Complex vector spaces
└── README.md              # This documentation
```

## Exercise Breakdown

### Foundation Operations (ex00-ex02)

#### Exercise 00: Add, Subtract and Scale

**Mathematical Concept**: Basic vector space operations

**Implementation**: Element-wise operations on vectors with error handling for dimension mismatches.

```cpp
template<typename T>
Vector<T> add(const Vector<T> &u, const Vector<T> &v) {
    // Validates dimensions and performs u + v
}
```

**Key Learning**: 
- Vector addition: `(u + v)[i] = u[i] + v[i]`
- Scalar multiplication: `(αu)[i] = α · u[i]`
- Dimension compatibility requirements

#### Exercise 01: Linear Combination

**Mathematical Concept**: Linear combinations as fundamental vector space constructions

**Implementation**: Computes `Σ(αᵢ · vᵢ)` for coefficient vector α and vector set {vᵢ}

```cpp
template<typename T>
Vector<T> linear_combination(const std::vector<Vector<T>> &vectors, 
                           const std::vector<T> &coeffs);
```

**Key Learning**:
- Span of vectors: all possible linear combinations
- Linear independence and dependence
- Basis vectors and coordinate systems

#### Exercise 02: Linear Interpolation

**Mathematical Concept**: Parametric interpolation between vectors

**Implementation**: Two equivalent formulations:
- `lerp(u, v, t) = u + t(v - u)`
- `lerp(u, v, t) = (1-t)u + tv`

**Key Learning**:
- Convex combinations when t ∈ [0,1]
- Affine transformations and barycentric coordinates
- Geometric interpretation of parameter space

### Vector Metrics and Properties (ex03-ex06)

#### Exercise 03: Dot Product

**Mathematical Concept**: Inner product defining geometric relationships

**Implementation**: 
```cpp
template<typename T>
T dot(const Vector<T> &u, const Vector<T> &v) {
    return Σ(u[i] * v[i]);  // For real vectors
    return Σ(u[i] * conj(v[i]));  // For complex vectors
}
```

**Key Learning**:
- Geometric interpretation: `u·v = |u||v|cos(θ)`
- Orthogonality: `u ⊥ v ⟺ u·v = 0`
- Bilinearity and symmetry properties

#### Exercise 04: Vector Norms

**Mathematical Concept**: Distance measures in vector spaces

**Implementation**: Three fundamental norms:

```cpp
// L¹ norm (Manhattan distance)
T norm_1(u) = Σ|u[i]|

// L² norm (Euclidean distance)  
T norm(u) = √(u·u)

// L∞ norm (Maximum norm)
T norm_inf(u) = max{|u[i]|}
```

**Key Learning**:
- Norm properties: non-negativity, definiteness, homogeneity, triangle inequality
- Different geometric interpretations (diamond, circle, square)
- Applications in optimization and error analysis

**Visual Representation**:
```
Unit circles in different norms:
L¹: ◇  L²: ○  L∞: □
```

#### Exercise 05: Angle and Cosine

**Mathematical Concept**: Angular relationships between vectors

**Implementation**:
```cpp
T angle_cos(u, v) = (u·v) / (|u||v|)
```

**Key Learning**:
- Cauchy-Schwarz inequality: `|u·v| ≤ |u||v|`
- Geometric interpretation of dot product
- Orthogonal and parallel vector detection

#### Exercise 06: Cross Product

**Mathematical Concept**: Vector product in 3D space

**Implementation**:
```cpp
Vector<T> cross_product(u, v) = [u₂v₃ - u₃v₂, u₃v₁ - u₁v₃, u₁v₂ - u₂v₁]
```

**Key Learning**:
- Right-hand rule and orientation
- Area of parallelogram: `|u × v|`
- Anti-commutativity: `u × v = -(v × u)`

### Matrix Operations (ex07-ex09)

#### Exercise 07: Matrix Multiplication

**Mathematical Concept**: Linear transformation composition

**Implementation**:
```cpp
// Matrix-vector multiplication
(Av)[i] = Σⱼ A[i,j] * v[j]

// Matrix-matrix multiplication  
(AB)[i,k] = Σⱼ A[i,j] * B[j,k]
```

**Key Learning**:
- Linear transformations as matrices
- Composition of transformations
- Dimension requirements: (m×n)(n×p) → (m×p)

#### Exercise 08: Trace

**Mathematical Concept**: Sum of diagonal elements

**Implementation**:
```cpp
T trace(A) = Σᵢ A[i,i]
```

**Key Learning**:
- Invariant under similarity transformations
- Sum of eigenvalues
- Applications in optimization and statistics

#### Exercise 09: Transpose

**Mathematical Concept**: Matrix reflection across main diagonal

**Implementation**:
```cpp
(Aᵀ)[i,j] = A[j,i]
```

**Key Learning**:
- Geometric interpretation: reflection
- Properties: (Aᵀ)ᵀ = A, (AB)ᵀ = BᵀAᵀ
- Symmetric matrices: A = Aᵀ

### Advanced Matrix Algorithms (ex10-ex12)

#### Exercise 10: Row Echelon Form

**Mathematical Concept**: Gaussian elimination algorithm

**Implementation**: Systematic elimination to upper triangular form

**Key Learning**:
- Elementary row operations
- Pivot selection strategies
- Rank determination through elimination

```
Example transformation:
[1  2  3]    [1  2   3 ]
[2  4  7] -> [0  0   1 ]
[1  3  5]    [0  0   0 ]
```

#### Exercise 11: Determinant

**Mathematical Concept**: Scalar measure of linear transformation scaling

**Implementation**: Two approaches:
- Cofactor expansion: `det(A) = Σⱼ(-1)ⁱ⁺ʲ aᵢⱼ det(Mᵢⱼ)`
- Gaussian elimination with pivot tracking

**Key Learning**:
- Geometric interpretation: signed volume scaling
- Properties: det(AB) = det(A)det(B)
- Invertibility: A invertible ⟺ det(A) ≠ 0

#### Exercise 12: Matrix Inverse

**Mathematical Concept**: Multiplicative inverse in matrix algebra

**Implementation**: Gauss-Jordan elimination on augmented matrix [A|I]

**Key Learning**:
- Existence conditions: det(A) ≠ 0
- Uniqueness: if exists, then unique
- Applications: solving linear systems Ax = b → x = A⁻¹b

### Matrix Analysis (ex13-ex14)

#### Exercise 13: Rank and Nullity

**Mathematical Concept**: Fundamental theorem of linear algebra

**Implementation**:
```cpp
rank(A) = number of linearly independent rows/columns
nullity(A) = dim(null(A)) = n - rank(A)
```

**Key Learning**:
- Rank-nullity theorem: rank(A) + nullity(A) = n
- Connection to solvability of linear systems
- Geometric interpretation: dimension of range and null space

#### Exercise 14: Projection Matrix

**Mathematical Concept**: Perspective projection for 3D graphics

**Implementation**: Perspective projection matrix construction

**Key Learning**:
- Homogeneous coordinates
- Perspective divide and viewport transformation
- Applications in computer graphics and computer vision

### Complex Vector Spaces (ex15)

**Mathematical Concept**: Extension to complex field ℂ

**Implementation**: Complete complex number class with template integration

**Key Learning**:
- Field properties of complex numbers
- Complex inner products: `⟨u,v⟩ = Σᵢ uᵢv̄ᵢ`
- Hermitian matrices and unitary transformations
- Applications in quantum mechanics and signal processing

```cpp
// Complex arithmetic
Complex<float> z1(3, 4);  // 3 + 4i
Complex<float> z2(1, -2); // 1 - 2i
auto product = z1 * z2;   // 11 - 2i

// Complex vectors work with all operations
Vector<Complex<float>> cv = {z1, z2};
auto norm_val = norm(cv);  // Real-valued norm
```

## Core Components

### Vector Class

Template-based vector implementation supporting:
- Dynamic sizing with bounds checking
- Operator overloading for intuitive syntax
- STL compatibility and iterators
- Memory-efficient storage

### Matrix Class

Row-major matrix implementation featuring:
- Efficient indexing with operator()(i,j)
- Dynamic memory management
- Template specialization for performance
- Exception safety guarantees

### Complex Class

Full-featured complex number implementation:
- Arithmetic operations with proper mathematical semantics
- Integration with existing template system
- Magnitude and argument calculations
- Stream operators for I/O

## Implementation Details

### Template Metaprogramming

Extensive use of C++17 template features:
```cpp
if constexpr (std::is_arithmetic_v<T>) {
    // Optimized path for built-in types
} else {
    // General path for user-defined types
}
```

### Performance Optimizations

- **FMA Instructions**: `std::fma` for improved precision and performance
- **Memory Layout**: Contiguous storage for cache efficiency
- **Template Specialization**: Type-specific optimizations
- **RAII**: Automatic resource management

### Error Handling

Comprehensive error checking:
- Dimension compatibility validation
- Null pointer checks
- Division by zero protection
- Exception safety guarantees

## Performance Considerations

### Computational Complexity

| Operation | Complexity | Memory |
|-----------|------------|---------|
| Vector Addition | O(n) | O(1) |
| Matrix Multiplication | O(n³) | O(1) |
| Determinant (Cofactor) | O(n!) | O(n) |
| Determinant (Gaussian) | O(n³) | O(1) |
| Matrix Inverse | O(n³) | O(n²) |

### Memory Usage

- **Vectors**: sizeof(T) × size + overhead
- **Matrices**: sizeof(T) × rows × cols + overhead
- **Complex**: 2 × sizeof(T) per element

## Theoretical Background

### Linear Algebra Fundamentals

**Vector Spaces**: The foundation of linear algebra, providing the abstract framework for all operations.

**Linear Transformations**: Functions T: V → W satisfying:
- T(u + v) = T(u) + T(v)
- T(αv) = αT(v)

**Matrix Representation**: Every linear transformation can be represented as a matrix relative to chosen bases.

### Numerical Methods

**Stability**: Algorithms must handle floating-point precision limitations.

**Conditioning**: Well-conditioned problems have stable solutions; ill-conditioned problems amplify errors.

**Convergence**: Iterative methods require convergence analysis and stopping criteria.

## Advanced Features

### Template Metaprogramming

Compile-time dispatch for optimal performance:
```cpp
template<typename T>
constexpr bool is_complex_v = /* implementation */;

template<typename T>
auto norm_implementation() {
    if constexpr (is_complex_v<T>) {
        return complex_norm_algorithm();
    } else {
        return real_norm_algorithm();
    }
}
```

### SFINAE and Concepts

Type requirements enforcement:
```cpp
template<typename T>
requires std::is_arithmetic_v<T>
T determinant(const Matrix<T>& A);
```

### Exception Safety

Strong exception safety guarantees through RAII and careful resource management.

## Glossary

### A

**Affine Transformation**: A geometric transformation that preserves points, straight lines, and planes. Includes translation, rotation, scaling, and shearing. Unlike linear transformations, affine transformations can include translation (moving objects without rotating or scaling them).

**Angle Between Vectors**: The geometric angle θ between two vectors u and v, calculated using the dot product formula: cos(θ) = (u·v)/(|u||v|). This angle ranges from 0° (parallel vectors pointing in the same direction) to 180° (parallel vectors pointing in opposite directions).

**Associativity**: A fundamental property where the grouping of operations doesn't affect the result. For vectors: (u + v) + w = u + (v + w). For matrices: (AB)C = A(BC).

### B

**Basis**: A set of linearly independent vectors that span a vector space. Every vector in the space can be written as a unique linear combination of basis vectors. For example, {(1,0), (0,1)} is the standard basis for 2D space.

**Bilinearity**: A property of operations involving two vector inputs where the operation is linear in each input separately. The dot product is bilinear: u·(αv + βw) = α(u·v) + β(u·w).

### C

**Cauchy-Schwarz Inequality**: A fundamental inequality stating that |u·v| ≤ |u||v| for any vectors u and v. This inequality ensures that the cosine of the angle between vectors is always between -1 and 1.

**Closure**: A property of vector spaces where performing an operation on elements within the space always produces another element within the same space. If u and v are in vector space V, then u + v must also be in V.

**Cofactor**: In matrix determinant calculation, the cofactor of element a[i,j] is (-1)^(i+j) times the determinant of the matrix obtained by removing row i and column j. Used in cofactor expansion for computing determinants.

**Commutativity**: A property where the order of operands doesn't affect the result. Vector addition is commutative: u + v = v + u. However, matrix multiplication is generally not commutative: AB ≠ BA.

**Complex Conjugate**: For a complex number z = a + bi, its conjugate is z* = a - bi. Used in complex vector operations, particularly in defining inner products for complex vector spaces.

**Complex Number**: A number of the form a + bi where a and b are real numbers and i is the imaginary unit (i² = -1). Extends real numbers to solve equations like x² + 1 = 0.

**Cross Product**: An operation on two 3D vectors that produces a third vector perpendicular to both original vectors. For vectors u and v, u × v has magnitude |u||v|sin(θ) and direction given by the right-hand rule.

### D

**Determinant**: A scalar value computed from a square matrix that provides important information about the matrix. Geometrically, it represents the signed volume scaling factor of the linear transformation represented by the matrix. A matrix is invertible if and only if its determinant is non-zero.

**Dimension**: The number of vectors in any basis for a vector space. This represents the number of independent directions or degrees of freedom in the space. For example, 3D space has dimension 3.

**Distributivity**: A property relating two operations. For vectors and scalars: α(u + v) = αu + αv (scalar multiplication distributes over vector addition).

**Dot Product**: Also called scalar product or inner product, it's an operation that takes two vectors and returns a scalar. For vectors u = (u₁, u₂, ..., uₙ) and v = (v₁, v₂, ..., vₙ), the dot product is u·v = u₁v₁ + u₂v₂ + ... + uₙvₙ.

### E

**Eigenvalue**: A scalar λ such that Av = λv for some non-zero vector v (called an eigenvector). Eigenvalues represent how much the matrix stretches vectors in certain directions.

**Eigenvector**: A non-zero vector v such that Av = λv for some scalar λ (called an eigenvalue). These vectors maintain their direction under the linear transformation represented by matrix A.

**Element-wise Operations**: Operations performed independently on each corresponding pair of elements from two vectors or matrices. Vector addition is element-wise: (u + v)[i] = u[i] + v[i].

### F

**Field**: A mathematical structure with two operations (addition and multiplication) that satisfy certain properties. Common fields include real numbers (ℝ) and complex numbers (ℂ). Vector spaces are defined over fields.

**FMA (Fused Multiply-Add)**: A computer operation that computes a*b + c in a single step with higher precision than computing the multiplication and addition separately. Used for improved numerical accuracy in floating-point calculations.

### G

**Gaussian Elimination**: An algorithm for solving systems of linear equations by transforming the augmented matrix to row echelon form using elementary row operations.

**Gauss-Jordan Elimination**: An extension of Gaussian elimination that continues to reduced row echelon form, making it easier to read solutions directly and useful for computing matrix inverses.

### H

**Hermitian Matrix**: A complex matrix that equals its conjugate transpose: A = A*. These matrices have real eigenvalues and are the complex analogue of real symmetric matrices.

**Homogeneous Coordinates**: A coordinate system used in projective geometry where n-dimensional points are represented using (n+1)-dimensional vectors. Used in computer graphics for unified handling of transformations including translation.

### I

**Identity Matrix**: A square matrix with 1s on the main diagonal and 0s elsewhere. Denoted as I, it acts as the multiplicative identity: AI = IA = A for any compatible matrix A.

**Inner Product**: A generalization of the dot product that defines angles and lengths in vector spaces. For complex vector spaces, it involves complex conjugation: ⟨u,v⟩ = Σᵢ uᵢv̄ᵢ.

**Inverse Matrix**: For a square matrix A, its inverse A⁻¹ is a matrix such that AA⁻¹ = A⁻¹A = I. A matrix has an inverse if and only if its determinant is non-zero.

### L

**Linear Combination**: An expression of the form α₁v₁ + α₂v₂ + ... + αₙvₙ where the αᵢ are scalars and the vᵢ are vectors. This is the fundamental way to combine vectors in a vector space.

**Linear Dependence**: A set of vectors is linearly dependent if at least one vector can be written as a linear combination of the others. Equivalently, there exist coefficients (not all zero) such that α₁v₁ + α₂v₂ + ... + αₙvₙ = 0.

**Linear Independence**: A set of vectors is linearly independent if no vector can be written as a linear combination of the others. Equivalently, the only solution to α₁v₁ + α₂v₂ + ... + αₙvₙ = 0 is when all αᵢ = 0.

**Linear Interpolation (LERP)**: A method of finding intermediate values between two points. For vectors u and v with parameter t, lerp(u,v,t) = (1-t)u + tv gives a point on the line segment between u and v.

**Linear Transformation**: A function T: V → W between vector spaces that preserves vector addition and scalar multiplication: T(αu + βv) = αT(u) + βT(v).

### M

**Magnitude**: The length or size of a vector, computed using the norm. For vector v, the magnitude is |v| = √(v·v).

**Matrix**: A rectangular array of numbers arranged in rows and columns. Matrices represent linear transformations and systems of linear equations.

**Matrix Multiplication**: An operation combining two matrices to produce a third matrix. For matrices A (m×n) and B (n×p), the product AB is an m×p matrix where (AB)[i,k] = Σⱼ A[i,j]B[j,k].

**Minor**: A matrix obtained by deleting one row and one column from a larger matrix. Used in calculating determinants via cofactor expansion.

### N

**Norm**: A function that assigns a positive length or size to vectors. Common norms include L¹ (Manhattan), L² (Euclidean), and L∞ (maximum). All norms satisfy: non-negativity, definiteness, homogeneity, and triangle inequality.

**Null Space**: The set of all vectors v such that Av = 0 for a given matrix A. Also called the kernel of the linear transformation represented by A.

**Nullity**: The dimension of the null space of a matrix. Related to rank by the rank-nullity theorem: rank(A) + nullity(A) = number of columns in A.

### O

**Orthogonal**: Two vectors are orthogonal if their dot product is zero, meaning they are perpendicular. Orthogonal vectors are geometrically at right angles to each other.

**Orthogonality**: The property of being perpendicular. In linear algebra, orthogonal vectors, matrices, and transformations have special properties that simplify many calculations.

### P

**Parallelogram Rule**: A geometric interpretation of vector addition where the sum of two vectors u and v is represented as the diagonal of a parallelogram with sides u and v.

**Pivot**: In Gaussian elimination, the non-zero element used to eliminate other elements in its column. Pivot selection strategies affect numerical stability.

**Projection**: The operation of casting one vector onto another or onto a subspace. The projection of vector u onto vector v is ((u·v)/(v·v))v.

### R

**Rank**: The dimension of the column space (or row space) of a matrix. Equivalently, the number of linearly independent rows or columns. Represents the dimension of the output space of the linear transformation.

**Row Echelon Form**: A matrix form where each row starts with zeros followed by a non-zero pivot, and each pivot is to the right of pivots in rows above. Used in solving linear systems.

**Right-Hand Rule**: A convention for determining the direction of the cross product. Point fingers of right hand along first vector, curl toward second vector, thumb points in direction of cross product.

### S

**Scalar**: A single number (as opposed to a vector or matrix). In vector spaces, scalars are elements of the underlying field (like real or complex numbers) used to scale vectors.

**Scalar Multiplication**: The operation of multiplying a vector by a scalar, scaling the vector's magnitude while preserving its direction (unless the scalar is negative, which reverses direction).

**Span**: The set of all linear combinations of a given set of vectors. The span of vectors {v₁, v₂, ..., vₙ} is the set {α₁v₁ + α₂v₂ + ... + αₙvₙ : αᵢ ∈ ℝ}.

**Square Matrix**: A matrix with the same number of rows and columns. Only square matrices have determinants, traces, and can potentially have inverses.

**Symmetric Matrix**: A matrix that equals its transpose: A = Aᵀ. For real matrices, symmetric matrices have real eigenvalues and orthogonal eigenvectors.

### T

**Template Metaprogramming**: A C++ technique that uses templates to perform computations at compile time. Allows writing generic code that works with different types while maintaining performance.

**Trace**: The sum of the diagonal elements of a square matrix: tr(A) = Σᵢ A[i,i]. The trace equals the sum of eigenvalues and is invariant under similarity transformations.

**Transpose**: The operation that reflects a matrix across its main diagonal, turning rows into columns. For matrix A, the transpose Aᵀ satisfies (Aᵀ)[i,j] = A[j,i].

**Triangle Inequality**: A fundamental property of norms stating that |u + v| ≤ |u| + |v|. Geometrically, the length of one side of a triangle cannot exceed the sum of the lengths of the other two sides.

### U

**Unit Vector**: A vector with magnitude 1. Any non-zero vector can be normalized to a unit vector by dividing by its magnitude: û = u/|u|.

**Unitary Matrix**: A complex matrix U such that U*U = UU* = I, where U* is the conjugate transpose. The complex analogue of orthogonal matrices.

### V

**Vector**: A mathematical object with both magnitude and direction, represented as an ordered list of numbers. Can represent physical quantities like velocity or abstract mathematical entities.

**Vector Addition**: The operation of combining two vectors element-wise: (u + v)[i] = u[i] + v[i]. Geometrically represented by the parallelogram rule or head-to-tail method.

**Vector Space**: A mathematical structure consisting of vectors that can be added together and multiplied by scalars, satisfying specific axioms (closure, associativity, commutativity, identity elements, etc.).

### Z

**Zero Vector**: The additive identity element in a vector space, denoted 0. Adding the zero vector to any vector v gives v: v + 0 = v. All components of the zero vector are zero.

## Documentation

### Mathematical References

- *Linear Algebra Done Right* by Sheldon Axler
- *Introduction to Linear Algebra* by Gilbert Strang
- *Numerical Linear Algebra* by Trefethen and Bau

### Implementation References

- *Effective Modern C++* by Scott Meyers
- *C++ Templates: The Complete Guide* by Vandevoorde and Josuttis
- *Numerical Recipes* by Press et al.

## License

This project is developed as part of the 42 curriculum. Educational use permitted with attribution.

---

**Note**: This implementation prioritizes educational clarity and mathematical correctness over maximum performance optimization. For production applications requiring extreme performance, consider specialized libraries like BLAS, LAPACK, or Eigen.
