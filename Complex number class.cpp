// PHYS 30762 Programming in C++
// Assignment 5 - skeleton code

// Class for complex numbers

#include<iostream>
#include<cmath>
#include<string.h>

class complex
{
//Make function to overload operator<< a friend
friend std::ostream & operator<<(std::ostream &os, const complex &z);
//Make function to overload operator>> a friend
friend std::istream & operator>>(std::istream &is, const complex &z);

private:
  double re,im;

public:
  //Default constructor
  complex(){re=im=0;}
  //Parameterised constructor
  complex(double real_part, double im_part){re=real_part; im=im_part;}

  //Destructor
  ~complex(){std::cout<<"Destroying complex number"<<std::endl;}

  // Return real component
  double real_return_func(){
      return re;
  }

  // Return imaginary component
  double im_return_func(){
      return im;
  }

  // Return modulus
  double modulus_func(){
      return sqrt(pow(im, 2) + pow(re, 2));
  }

  // Return argument
  double argument_func(){
    if(re>0){
      return atan(im/re);
    } else if(re<0 && im>=0){
      return atan(im/re) + M_1_PI;
    } else if(re<0 && im<0){
      return atan(im/re) - M_1_PI;
    } else if(re==0 && im>0){
      return M_1_PI / 2;
    } else if(re==0 && im>0){
      return -M_1_PI / 2;
    } else {
      return 0;
    }
  }

  // Return complex conjugate
  complex complex_conj_func(){
    complex number_conj{re, -1*im};
    
    return number_conj;
  }

  // Overload + operator for addition
  complex operator +(const complex &z) const
  {
    complex new_number{re + z.re, im + z.im};
    return new_number;
  }

  // Overload - operator for subtraction
  complex operator -(const complex &z) const
  {
    complex new_number{re - z.re, im - z.im};
    return new_number;
  }

  // Overload * operator for multiplication, z1*z2
  complex operator *(const complex &z) const
  {
    complex new_number{re * z.re - im * z.im, im * z.re + re * z.im};
    return new_number;
  }

  // Overload / operator for division, z1/z2
  complex operator /(const complex &z) const
  {
    complex numerator{re * z.re + im * z.im, im * z.re - re * z.im};
    complex denominator{pow(z.re, 2) + pow(z.im, 2), 0};
    complex fraction{numerator.re / denominator.re, numerator.im / denominator.re};
    return fraction;
  }

};

// Function to overload << operator for complex numbers
std::ostream & operator<<(std::ostream &os, const complex &z){
  if(z.im > 0){
    os<<std::to_string(z.re)<<" + "<<std::to_string(z.im)<<"i";
  } else if(z.im < 0){
    os<<std::to_string(z.re)<<" "<<std::to_string(z.im)<<"i";
  } else{
    os<<std::to_string(z.re)<<" + "<<std::to_string(z.im)<<"i";
  }
  return os;
}

//Function to overload >> operator for complex numbers
std::istream & operator>>(std::istream &os, complex &z){
  std::string re_string;
  std::string operation;
  std::string im_string;
  complex number;
  double re_part;
  double im_part;
  os>>re_string>>operation>>im_string;
  if(operation == "-"){
      re_part = atof(re_string.c_str());
      im_part = -1 * atof(im_string.c_str());

    } else if(operation == "+"){
      re_part = atof(re_string.c_str());
      im_part = -1 * atof(im_string.c_str());

    } else{
      std::cout<<"Your input was not recognised"<<std::endl;
    }
    const complex temp{re_part, im_part};
    z = temp;
    
    return os;
}




int main()
{  
  std::cout.precision(3);

  complex a{3,4};
  complex b{1,-2};
  
  complex c{b.complex_conj_func()};
  double d{b.argument_func()};
  double e{b.modulus_func()};
  complex f{a * b};
  complex g{a / b};
  complex h{a + b};
  complex i{a - b};

  std::cout<<"Conjugate of b: "<<c<<std::endl;
  std::cout<<"Argument of b: "<<d<<std::endl;
  std::cout<<"a * b: "<<f<<std::endl;
  std::cout<<"a / b: "<<g<<std::endl;
  std::cout<<"a + b: "<<h<<std::endl;
  std::cout<<"a - b: "<<i<<std::endl;
  std::cout<<"Imaginary part of a: "<<a.im_return_func()<<std::endl;
  std::cout<<"Real part of a: "<<a.real_return_func()<<std::endl;

  //Extraction of complex number from istream
  complex number_input;
  std::cout<<"Please enter a complex number in the form a + bi"<<std::endl;
  std::cin>>number_input;
  std::cout<<number_input<<std::endl;

  std::cout<<number_input.real_return_func()<<std::endl;
  std::cout<<number_input.im_return_func()<<std::endl;
  std::cout<<number_input + a<<std::endl;


  return 0;
}