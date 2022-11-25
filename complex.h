#include <iostream>
#ifndef COMPLEX
#define COMPLEX


class Complex
{
private:
 
    double   Real;
    double  Imag;
    double  Mag;
    double  Angle;
    bool    NaN;

public:
    Complex();//default constructor
    Complex(double onlyReal);// only real constructor
    Complex(double Real1, double Imag1); // real and imaginary constructor 
    void           setComplex(double real, double imag); // Setter for real and imaginary parts
    void           setAngle(double value); // setter for Angle
    void           setMag(double value);// setter for mag
    double  const  getReal(); // setter for real  
    double  const  getImag(); // getter for imag
    double  const  getAngle(); // getter for Angle
    double  const  getMag();// getter for mag
    bool    const  getNaN();// getter for naN
    void    const  displayPolar(); // Displays polar in Radians 
    void           ConvertPolar(); // converts to polar form 
    void           convertRect(); // converts to rectangular form 
    void    const    displayRect(); // displays the rectangular form
    Complex        Conjugate();     // computes and outputs the conjugate
    Complex        operator+(Complex); // overloads for +
    Complex        operator-(Complex); // overload for -
    friend Complex operator*(Complex,Complex); // overload for *
    Complex        operator/(Complex); // overload for /
    friend std::ostream & operator << (std::ostream &out,  Complex &c);  
};
 inline std::ostream & operator << (std::ostream &out,  Complex &c)
{
    c.displayRect();
    return out;
}

#endif