#pragma once

#include <iostream>
#include <vector>


class Matrix{
private:
	std::vector<std::vector<double> > mData;
	int mNumRows, mNumCols ;

public:
	Matrix(const std::vector<std::vector<double> >& mat);  // Default constructor

	int GetNumberOfRows() const;
	int GetNumberOfCols() const;

	Matrix operator+(const Matrix& m1) const; 	// Binary +
	Matrix operator-(const Matrix& m1) const;	// Binary -
	Matrix operator+() const; 			// Unary +
	Matrix operator-() const;			// Unary -

	friend Matrix operator*(double s, Matrix m1);   // Scaling
	friend std::ostream& operator<<(std::ostream& stream, const Matrix& m1);

};

