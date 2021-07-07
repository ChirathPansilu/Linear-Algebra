from matrix import Mat

mat1 = Mat([[1,2,3],[4,5,6],[7,8,9],[3,3,2]])
matM = Mat([[4,5,6],[7,8,9],[1,2,3]])
mat5 = mat1 * matM
matDet = Mat([[1, 2, 3, 90, 0], [4, 5, 6, 23, 90], [7, 8, 9, 234, 236], [3, 3, 2, 83, 34], [3, 0, 0, 2, 2]])
matAdj = Mat([[1,0,2],[-1,3,1],[2,5,-2]])

print("Get the Minor of element at (1,4) in the below matrix\n")
print(matDet)
print()
print(Mat.minor(matDet,3))
print()

print("Det of Above Original Matrix:")
print(Mat.det(matDet))
input()

print(Mat.minorMat(matDet, 3,2))
print()
print(Mat.cofactorMat(matAdj))
