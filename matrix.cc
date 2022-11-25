/*
Austin Toro 
ECE 2036 Lab5
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include "complex.h"
#include "matrix.h"
using namespace std;
 Matrix ::  ~Matrix() // Destructor 
{
    delete [] cptr;
   
}

Matrix :: Matrix(int qrows, int qcolumns) // Constructor
{

  rows=qrows;
  columns=qcolumns;
  size=rows*columns;
  nan=false;
  cptr= new Complex[rows * columns]; 

}


Matrix :: Matrix( Matrix const  &d) // Copy constructor
 // Creates a copy of a matrix and stores it into a new object
 {
  
  rows = d.rows;
  columns=d.columns;
  size= rows*columns;
  cptr =new Complex[size];
 for (int i = 1; i <= d.rows; i++) 
        for (int j = 1; j <= d.columns; j++) 
  {
    {       int index =columns *(i-1)+(j-1);
            cptr[index] = d(i,j);
    }
  }

 }

void const Matrix :: printMatrix() // Prints the matrix
{
  // goes through each index of the array and just prints the value
  // The logic that is added formats the array into matrix format 
  int counter = 0 ;
 
  
  for(int i = 0 ; i < size; i++)
    { 
      if(counter==columns- 1)
        {
        cout << setw(10) << cptr[i]<< endl;
        counter = 0;
        }
      else 
        {
            cout << setw(10)<< cptr[i] << setw(10);
            counter++;          
        }
      if(i==size-1)
        {
          cout << endl;
        }
      }
    

}


Matrix  const Matrix :: Transpose()// Transposes the matix
// This function iterates through the matrix and swaps the rows and columns
{
   Matrix transpose(this->getRows(),this->getColumns());
  
  for(int i= 1; i <= this->getRows() ; i++)
    for(int j=1; j <= this->getColumns(); j++)
  {

    {

     transpose(i,j)= (*this)(j,i);
    }

  }

  return transpose;
}

Matrix Matrix :: operator+(Matrix &RHS)// Matrix Addition overload
// This function checks if the dimsions agree and if they do it performs 
// adition on each index of the matrix
{
   Matrix sum(this->rows, this->columns);
if (this->getRows()!=RHS.getRows() && this ->getColumns() != RHS.getColumns())
 {
 
       sum.nan=true;
        return sum;
        
 }
      else 
      {
        for(int i=1;i<= sum.getRows();i++)
          for(int j=1; j <=sum.getColumns(); j++)
            {
               sum(i,j) = (*this)(i,j)+RHS(i,j);
            }
        return sum;
         sum.nan=false;
      }
    
}


Matrix  Matrix :: operator~()// Overloads the ~ operator to return the traspose
{

return this->Transpose();



}
Matrix Matrix :: operator=(const Matrix & RHS )// This is the assigmnet operator
// this checks if nan is true if it is it explicitly sets it to true and
// outputs the text below, if nan is false it deletes the old pointer
//makes a new pointer with the same size as the one passed 
// and finaly equates the two matricies
{
  if (RHS.nan==true)
  {
    cout << "Dimensions don't agree" << endl;
     cout << "This matrix has No elements " << endl;
     this->setnan(true);
     return (*this);
  }
   else{
      delete [] this->cptr;
      this->size=RHS.size;
      this->rows=RHS.rows;
      this->columns=RHS.columns;
      this->cptr = new Complex[RHS.size];
        for (int i = 1; i <= RHS.rows; ++i) {
            for (int j = 1; j <= RHS.columns; ++j) {
            (*this)(i,j) = RHS(i,j);
        }
    }
 
    return *this;
   }
}

Matrix Matrix :: operator-(Matrix &D)// Matrix subtraction
{
  // Checks if the dimensions are correct if they are it performs matrix subtraction 
  // if they arent it sets diff.nan to truel
  Matrix diff(D.getRows(),D.getColumns());
if (this->getRows()==D.getRows() && this ->getColumns() == D.getColumns())
  {
          for(int i=1;i<=rows;i++)
          for(int j=1; j <=columns; j++)
            {
               diff(i,j) = D(i,j)-(*this)(i,j);
            }


      return diff;
  }
      else 
      {
        diff.nan=true;
        return diff;
      }
}
Matrix   Matrix :: operator!()// Conjugate Transpose
// takes the matrix, creates a new matrix  and performs the conjugate of every index
// and puts that result in the new matrix then returning the transpose of the new matrix
{
  Matrix ctrans(this->getRows(),this->getColumns());
  Complex temp;
  Complex tempc;
  ctrans.nan=false;
  for(int i= 1; i <= ctrans.getRows() ; i++)
    for(int j=1; j <= ctrans.getColumns(); j++)
  {
        temp=(*this)(i,j);
        tempc=temp.Conjugate();
        ctrans(i,j)=tempc;
  }

return ctrans.Transpose();
}

 Matrix  operator*(Matrix  &LHS,Complex RHS) //Overload for Matrix*complex
// Creates a new matrix and stores the result of 
{

 Matrix result(LHS.getRows(),LHS.getColumns());
    
    for (int i = 1; i <= LHS.getRows(); i++)
    {
        for (int j = 1; j <= LHS.getColumns(); j++)
        {
            result(i,j) = LHS(i,j) * RHS;
          
          
        }
    }
  
    return result;
}

 Matrix  operator*(Complex RHS,Matrix  &LHS)

{

 Matrix result(LHS.getRows(),LHS.getColumns());
    
    for (int i = 1; i <= LHS.getRows(); i++)
    {
        for (int j = 1; j <= LHS.getColumns(); j++)
        {
            result(i,j) = LHS(i,j) * RHS;
          
          
        }
    }
    
    return result;
}

Matrix Matrix ::  operator*(Matrix & B) // Matrix multiplication 
// Makes sure the dimensions match then creates three loops
// two for iterating through the matrix and one for keeping a sum 
// after each row* column for an i and j it resets and starts the count again 
// until it reaches the end of the matrix and it stores this result in a new matrix
{
   Matrix prod(this->getRows(),B.getColumns());
    if(this->getColumns() != B.getRows())
    {
         prod.nan=true;
        return prod;
    }
    else
    { 
        Complex temp = Complex(0,0);
        for (int i = 1; i <= this->getRows(); i++)
        {
            for (int j = 1; j <= B.getColumns(); j++)
            {
                temp = Complex(0,0);
                for (int k = 0; k <= B.getColumns(); k++)
                {
                    temp = ((*this)(i,k) * B(k,j))+temp;
                }
                prod(i,j) = temp;
               
            }
            
        }
        return prod;






    }
}
   Complex & Matrix :: operator()(int i, int j)// Indexing operator
   // Takes i and j decrements them by to account for zero indexing and 
   // converts to the 1D equivalent
 {
   int r=i-1;
   int c =j-1;
   int  index2 = r * this->getColumns() + c;
  // cout << index2-4 << endl;;
  
   return cptr[index2];
 }

 Complex & Matrix :: operator()(int i, int j)const // constant versiion of
 // the above function to deal with edge cases that use constant data
 {
   int r=i-1;
   int c =j-1;
   int  index2 = r * columns + c;
  
  
   return cptr[index2];
 }
 

