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


Matrix Matrix::operator*(const Matrix& m1) const{
	assert(mNumCols == m1.mNumRows);

	std::vector<std::vector<double> > output;

	for(int r=0; r<mNumRows; r++){
		std::vector<double> tempRow;

		for(int c=0; c<mNumCols; c++){
			double tempSum = 0;

			for(int e=0; e<mNumCols; e++){
				tempSum += mData[r][e] * m1.mData[e][c];
			}
			tempRow.push_back(tempSum);
		}
		output.push_back(tempRow);	
	}
	return {output};
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
			stream << std::setw(6) << m1.mData[r][c] ;
		}
		stream << '\n';
	}
	return stream;
}

Matrix Matrix::getMinorMat(int row, int col) const{
	assert( row >= 0 && row < mNumRows && col >= 0 && col < mNumCols);

	std::vector<std::vector<double> > output;

	for(int r=0;r<mNumRows;r++){
		if(r!=row){
			std::vector<double> tempRow(mData[r].begin(), mData[r].begin()+col);
			tempRow.insert(tempRow.end(), mData[r].begin()+col+1, mData[r].end());
			output.push_back(tempRow);
		}
	}

	return {output};
}

double det(const Matrix& m1){
	assert( m1.mNumRows == m1.mNumCols );

	if( m1.mNumRows==2 ){
		return ( m1.mData[0][0] * m1.mData[1][1] - m1.mData[0][1] * m1.mData[1][0] );
	}
	
	double output=0;

	//Using first row to calculate determinant
	for( int c=0; c<m1.mNumCols; c++ ){
		if(c%2==0){
			output += m1.mData[0][c] * det(m1.getMinorMat(0,c));
		}else{
			output -= m1.mData[0][c] * det(m1.getMinorMat(0,c));
		}
	}
	return output;
}
