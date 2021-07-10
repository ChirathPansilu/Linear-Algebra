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

	M3 = M2;

	std::cout << +M3 << std::endl;
	std::cout << -M3 << std::endl;


	std::cout << 3*M1 << std::endl;

	std::cout << M1*M2 << std::endl;

	std::cout << M1 << std::endl;
	std::cout << det(M2) << std::endl;

	std::cout << M2.transpose() << std::endl;
	std::cout << adj(M2) << std::endl;
	std::cout << M2.inverse() << std::endl;
}
