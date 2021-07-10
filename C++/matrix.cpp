#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>
#include "matrix.h"


Matrix::Matrix(const std::vector<std::vector<double> >& mat){
	mData = mat;

	mNumRows = mat.size();
	mNumCols = mat[0].size();
}


int Matrix::GetNumberOfRows() const{
	return mNumRows;
}


int Matrix::GetNumberOfCols() const{
	return mNumCols;
}


Matrix Matrix::operator+(const Matrix& m1) const{
	assert( mNumRows == m1.GetNumberOfRows() && mNumCols == m1.GetNumberOfCols() );

	std::vector<std::vector<double> > output(m1.mData);
	
	for(int i=0; i<mNumRows; i++){
		for(int j=0; j<mNumCols; j++){
			output[i][j] = mData[i][j] + m1.mData[i][j];
		}
	}	

	return {output};
}


Matrix Matrix::operator-(const Matrix& m1) const{
	assert( mNumRows == m1.GetNumberOfRows() && mNumCols == m1.GetNumberOfCols() );

	std::vector<std::vector<double> > output(m1.mData);
	
	for(int i=0; i<mNumRows; i++){
		for(int j=0; j<mNumCols; j++){
			output[i][j] = mData[i][j] - m1.mData[i][j];
		}
	}	

	return {output};
}


Matrix Matrix::operator+() const{
	return *this;
}


Matrix Matrix::operator-() const{

	Matrix output(*this);
	
	for(int i=0; i<mNumRows; i++){
		for(int j=0; j<mNumCols; j++){
			output.mData[i][j] *= -1;
		}
	}	

	return output;
}

Matrix operator*(double s, Matrix m1){

	for(int i=0; i<m1.mNumRows; i++){
		for(int j=0; j<m1.mNumCols; j++){
			m1.mData[i][j] *= s ;
		}
	}	

	return m1;
}

std::ostream& operator<<(std::ostream& stream, const Matrix& m1){
	for(int r=0; r < m1.mNumRows; r++){
		for(int c=0; c < m1.mNumCols; c++){
			stream << std::setw(4) << m1.mData[r][c] ;
		}
		stream << '\n';
	}
	return stream;
}
