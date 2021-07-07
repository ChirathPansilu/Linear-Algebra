'''Implement Matrix Class with matrix operations'''

class Mat:
    def __init__(self,mat):
        self.mat = mat
        self.rows = len(self.mat)
        self.cols = len(self.mat[0])


    def __repr__(self):
        out = '['
        for r in self.mat:
            out += repr(r)+',\n'
        out = out[:-2]+']' 
        return out


    def __add__(self,mat2):
        if(mat2.rows!=self.rows or mat2.cols!=self.cols):
            raise TypeError("Matrices should be of same order")

        out = []
        for row in range(self.rows):
            out.append([elem1+elem2 for elem1,elem2 in zip(self.mat[row], mat2.mat[row])])
        return Mat(out)


    def __sub__(self,mat2):
        if(mat2.rows!=self.rows or mat2.cols!=self.cols):
            raise Exception("Matrices should be of same order")

        out = []
        for row in range(self.rows):
            out.append([elem1-elem2 for elem1,elem2 in zip(self.mat[row], mat2.mat[row])])
        return Mat(out)


    def __mul__(self,mat2):
        if(self.cols!=mat2.rows):
            print(self.cols, mat2.rows)
            raise Exception(f"Cannot Multiply Matrices mat1 #columns{self.cols} should be equal to mat2 #rows{mat2.rows}")

        out = []
        for row in range(self.rows):
            temp_row = []
            for column in range(mat2.cols):
                temp = 0
                for elem in range(self.cols):
                    temp += self.mat[row][elem]*mat2.mat[elem][column]
                temp_row.append(temp)
            out.append(temp_row)
        return Mat(out)


    @staticmethod
    def minor(matrix,elem_id):
        if(matrix.rows!=matrix.cols):
            raise Exception(f"Should be a square matrix [{matrix.rows}x{matrix.cols}]")

        transpose =[list(row) for i,row in enumerate(zip(*matrix.mat[1:])) if i!=elem_id] 
        output = [list(row) for row in zip(*transpose)]
        return Mat(output)

    @staticmethod
    def det(matrix):
        if(matrix.rows!=matrix.cols):
            raise Exception(f"Should be a square matrix [{matrix.rows}x{matrix.cols}]")

        if(matrix.rows==matrix.cols==2):
            return matrix.mat[0][0]*matrix.mat[1][1]-matrix.mat[0][1]*matrix.mat[1][0]

        out = 0
        for elem_id, elem_row0 in enumerate(matrix.mat[0]):
            if(elem_id%2 ==0):
                out += elem_row0*Mat.det(Mat.minor(matrix,elem_id))
            else:
                out -= elem_row0*Mat.det(Mat.minor(matrix,elem_id))

        return out
