#include <iostream>
#include <vector>
#include "matrix.h"

int main(){
	std::vector<std::vector<double> > mat{{1,2,3},{4,5,6},{7,8,9}};

	Matrix mat1(mat);
	mat1.printMat();
}
