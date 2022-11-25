/*
Austin Toro 
ECE 2036 Lab5
*/
#ifndef MATRIX
#define MATRIX

#include <iostream>
#include "complex.h" 
#include <string>

class Matrix
{

private:

int rows; // Rows of Matrix
int columns; // columns of Matrix
int size; // size of Matrix 
int index; // Index of Matrix 
Complex * cptr; // pointer to manage data 
bool nan; // bool to tell if dimensions are mismatched


public:
~Matrix(); // Destructor 
Matrix(int rows, int columns); // Constructor
Matrix( Matrix const &d); // Copy constructor
int getSize(){return size;} // Getter for size
int getRows(){return rows;} // Getter for rows
int getColumns(){return columns;} // Getter for columns
bool getnan(){return nan;} // Getter for nan
void  setnan(bool value){ nan=value;} // setter for nan


void const printMatrix(); // Prints the matrix (constant)
Matrix const Transpose(); // Transposes the matrix (constant)
friend std::ostream& operator<< (std::ostream &, const Matrix &); // Overload for  <<
friend Matrix operator*(Matrix&, Complex); // Overload for Matrix*complex
friend Matrix operator*(Complex,Matrix&);// overload for complex*matrix
Matrix operator*(Matrix&); // oveload for matrix multiplication
Matrix operator+(Matrix&); // Overload for matrix addtion
Matrix operator-(Matrix&); // overload for matrix subtraction

Matrix operator~(); // Transpose 
Matrix operator!(); // Conjugate Transpose 
Matrix operator=(const Matrix &); // Assignment operator
Complex & operator()(int i,int j); // indexing operator
Complex & operator()(int i,int j)const; // const indexing operator




};
inline std::ostream & operator << (std::ostream &out,  Matrix &c)// overload of the  << 
//operator if the nan value of the matrix being called is true it prints it
// if it is not it then outputs a matrix with no rows and columns 
{
    
    if (c.getnan()==false)
    {
        c.printMatrix();
        return out;
    }
    else if(c.getnan()==true)
    {
        Matrix temp(0,0);
        out << temp <<std:: endl;
        return out;
    }
return out;
}

#endif