# -*- coding: utf-8 -*-
"""17_Matrix_operations.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1_WP5RJqwC9j3T7IvVzOTJLrB4jzsEj-M
"""

import numpy as np

"""**Creating matrix using numpy**"""

mat1 = np.array([[2,3],[6,7]])
print(mat1)

mat1.shape

mat2 = np.array([[10,20],[23,45],[15,23]])
print(mat2)

mat2.shape

"""**Creating matrices with Random values**"""

random_matrix = np.random.rand(3,3)
print(random_matrix)

# creating matrix with random integers
random_integer_matrix = np.random.randint(100,size=(4,5))
print(random_integer_matrix)

"""**Matrix with all the value as 1**"""

matrix3 = np.ones((2,3),dtype=int)
print(matrix3)

"""**Null matrix or Zeros matrix**"""

null_matrix = np.zeros((7,7))
print(null_matrix)

null_matrix1 = np.zeros((7,7),dtype=int)
print(null_matrix1)

"""**Identitiy Matrix**"""

identity_matrix = np.eye(3,3)
print(identity_matrix)

identity_matrix1 = np.eye(3,3,dtype=int)
print(identity_matrix1)

"""**Transpose of a matrix**"""

a = np.random.randint(100,size=(4,5))
print(a)

transpose_of_a = np.transpose(a)
print(transpose_of_a)

"""**Matrix Addition**"""

A = np.array([[2,3],[4,5]])

B = np.array([[6,7],[8,9]])

print(A)
print(B)

C = A+B
print(C)

# Creating two matrices with random values

m1 = np.random.randint(10,size=(3,3))

m2 = np.random.randint(20,size=(3,3))

print(m1)
print(m2)

sum = np.add(m1,m2)
print(sum)

diff = np.subtract(m1,m2)
print(diff)

"""Multiplying a matrix by a scalar"""

x = 5

 y =np.random.randint(10,size=(4,4))

 print(y)

product = np.multiply(x,y)
print(product)

"""**Multiplying the two matrices**"""

mat4 = np.random.randint(5,size=(3,4))
mat5 = np.random.randint(5,size=(4,5))

print(mat4)
print(mat5)

pro = np.dot(mat4,mat5)
print(pro)

pro.shape

"""**Element wise multiplications**  


**The shape of both matrices must be same for element wise multiplicaitons**
"""

pro1 =(mat4*mat5)
print(pro1)

