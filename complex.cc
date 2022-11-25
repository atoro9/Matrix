/*
Austin Toro 
ECE 2036 Lab5
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include "complex.h"
using namespace std;
const double pi = 3.14159; // defining pi to be used later in the code 
double const Complex ::  getReal(){return Real;} // getter for real
double const Complex ::  getMag(){return Mag;}// gettter for mag
double const Complex ::  getAngle(){return Angle;}//getter for angle
double const Complex ::  getImag(){return Imag;}// getter for imag
bool   const Complex ::  getNaN(){return NaN;}//getter for Nan

 Complex ::  Complex()//default constructor
    {
        setComplex(0,0);
        Angle=0;
        NaN=false;
        Mag=0;
    }
Complex :: Complex(double Real1, double Imag1) // real and imaginary constructor 
    {
        Real=Real1;
        Imag=Imag1;
    }
Complex :: Complex(double onlyReal)// only real constructor
    {
        setComplex(onlyReal,0);
        
    }

void Complex :: setAngle(double value)//sets angle
    {
        Angle=value;
    }
void Complex :: setMag(double value)//sets Mag
    {
        Mag=value;
    }
void  const Complex :: displayPolar() // Displays results in polar
// This function calls convert polar and then outputs the result
{
   if (getNaN()==false)

  {
        ConvertPolar();
        cout  << setprecision(7)<<  Mag <<" < " <<Angle << endl;
  }
    else if (getNaN()==true)
        cout << "NaN" << endl;

}

void Complex :: setComplex(double real, double imag)// setter for real and imaginary 
{

Real=real;
Imag=imag;

}


void const  Complex :: displayRect() // Displays the number in rectangular form 
// Just displays rean and imag with the presicion set to 7 if it is needed 
{
    
    if(NaN==false)
    {
        cout << setprecision(7)<< Real << "  +  "<< Imag << "j" << setw(5);
    }
    else if (NaN==true)
        cout << "NaN" << endl;
}
   

void Complex :: ConvertPolar()// Converts to polar 
{
   
    double temp2= (this->Real*this->Real)+(this->Imag*this->Imag);
   this-> Mag=sqrt(temp2);
    this->Angle=atan2(this->Imag,this->Real);


}

void Complex :: convertRect() // Converts to Rectagular form 
// this just sets real and imag according to the formula for doing so 
{
   this-> Real=this-> Mag * cos(this->Angle);
    this->Imag=this-> Mag * sin (this->Angle);
}

Complex Complex::operator+(Complex RHS)// overloads the + operator 
{// creates a new complex object and stores the sum of the real and the sum of the Imag
    Complex sum;
    sum.Imag = this->getImag()+RHS.Imag; 
    sum.Real= this->getReal()+ RHS.Real;
    return(sum);

 }
Complex Complex :: Conjugate()// computes and returns the conjugate
{
    ConvertPolar();
    this-> Angle=-this->Angle;
    convertRect();
    return *this;

}
 Complex Complex::operator-(Complex RHS)// Same thing as the sum but instead of 
 //addition it does subtraction
{

    Complex diff;

    diff.Imag = getImag() - RHS.Imag ; 
    diff.Real = getReal()- RHS.Real;

    return(diff);

 }

Complex operator*(Complex LHS,Complex RHS)// Completes the multiplication of complex numbers 
// explicipty defining the LHS and RHS for use in the later steps of the lab
// It follows the steps to convert multiply complex numbers converting to polar 
// multiplying the magnitudes and adding the angles 
{
    RHS.ConvertPolar();
    LHS.ConvertPolar();
    
    double mag=LHS.getMag()*RHS.getMag();
    double ang=LHS.getAngle()+RHS.getAngle();
    LHS.setMag(mag);
    LHS.setAngle(ang);
    LHS.convertRect();
    return(LHS);

 }

 Complex Complex::operator/(Complex RHS)// Computes division with error checking 
 // If you aren't dividing by zero it does the normal proces for dividing complex numbers
{
     Complex product;
    RHS.ConvertPolar();
  if(RHS.Mag==0)
  {
      
       product.NaN=true;
    
      return product;
     
  }
  else

    NaN=false;
    product.ConvertPolar();
    product.Mag=getMag()/RHS.Mag;
    product.Angle=getAngle()-RHS.Angle;
    product.convertRect();
   return(product);

 }
 