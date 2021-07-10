#pragma once

#include <iostream>
#include <vector>


class Matrix{
private:
	std::vector<std::vector<double> > mData;
	int mNumRows, mNumCols ;

	Matrix getMinorMat(int row, int col) const;
	Matrix cofactorMat() const;

public:
	Matrix(const std::vector<std::vector<double> >& mat);  // Specialized constructor

	int GetNumberOfRows() const;
	int GetNumberOfCols() const;

	Matrix operator+(const Matrix& m1) const; 	// Binary +
	Matrix operator-(const Matrix& m1) const;	// Binary -
	Matrix operator+() const; 			// Unary +
	Matrix operator-() const;			// Unary -
	Matrix operator*(const Matrix& m1) const; 	// Scalar Multiplication *

	friend Matrix operator*(double s, Matrix m1);   // Scaling
	friend std::ostream& operator<<(std::ostream& stream, const Matrix& m1);

	friend double det(const Matrix& m1); 	        // Determinant Value

};

