#pragma once

#include <iostream>
#include <vector>


class Matrix{
private:
	std::vector<std::vector<double> > mat;

public:
	Matrix(std::vector<std::vector<double> > m){
		mat = m;
		size_t rows = m.size();
		size_t cols = m[0].size();
	}

	void printMat(){
		for(auto r: mat){
			for(auto i: r){
				std::cout << i << " ";
			}
			std::cout << '\n';
		}
	}
};

