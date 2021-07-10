#include <iostream>
#include <vector>
#include "matrix.h"

int main(){
	std::vector<std::vector<double> > mat1{{1,2,3},{4,5,6},{7,8,9}};
	std::vector<std::vector<double> > mat2{{3,9,30},{43,15,63},{27,18,59}};


	Matrix M1(mat1);
	Matrix M2(mat2);
	
	Matrix M3 = M1+M2;	

	std::cout << M3 << std::endl;
}
