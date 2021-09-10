#include "fraction2.h"
#include <iostream>
#include <string>
#include <sstream>



fraction::fraction(int num, int denom){
	numerator = num;
	denominator = denom;
//	std::cout << numerator << "/" << denominator << std::endl;
}

fraction::fraction(){
	numerator = 1;
	denominator = 1;
//	std::cout << numerator << "/" << denominator << std::endl;
} 

fraction::fraction(const fraction &obj){
//	std::cout << "using copy constructor...." << std::endl;
	numerator = obj.numerator;
	denominator = obj.denominator;
//	std::cout << numerator << "/" << denominator << std::endl;
}

void fraction::reduce(void){
	int largest = 1;
	int i = 1;
	int divnum=0;
	int divdenum=0;
	int x = numerator;
	int y = denominator;
	
	for (i=1; i<=numerator; i++){
		divnum = x%i;
		divdenum = y%i;
		if(divnum==0 && divdenum==0){
			largest = i;
		}
	}	
	
	numerator = numerator/largest;
	denominator = denominator/largest;
		
}

void fraction::f_print(void){
	std::cout << numerator << "/" << denominator << std::endl;
}

bool operator== (const fraction &a, const fraction &b){
	fraction x = a;
	fraction y = b;
	x.reduce();
	y.reduce();
	return(x.numerator==y.numerator&&x.denominator==y.denominator);
}

bool operator!= (const fraction &a, const fraction &b){
	return !(a==b);
}

bool operator< (const fraction &a, const fraction &b){
	fraction x;
	fraction y;
	x.numerator = a.numerator*b.denominator;
	x.denominator = a.denominator*b.denominator;
	y.numerator = b.numerator*a.denominator;
	y.denominator = b.denominator*a.denominator;
	return(x.numerator < y.numerator);
}

bool operator> (const fraction &a, const fraction &b){
	fraction x;
	fraction y;
	x.numerator = a.numerator*b.denominator;
	x.denominator = a.denominator*b.denominator;
	y.numerator = b.numerator*a.denominator;
	y.denominator = b.denominator*a.denominator;
	
	return (x.numerator > y.numerator);
}

bool operator<= (const fraction &a, const fraction &b){
	
	return ((a==b) || (a<b));
}

bool operator>= (const fraction &a, const fraction &b){
	return ((a==b) || (a>b));
}

fraction::operator double()	//typecasting to double
{
	double value;  // double representing the fraction's decimal value
	int num = numerator;
	int denum = denominator;
	value = (static_cast<double> (num))/denum;
	return(value);
}

std::string fraction::toString(){
	std::string result;
	std::ostringstream ss;
	ss << numerator;
	result = ss.str();
	result = result + "/";
	ss.str("");
	ss << denominator;
	result = result+ss.str();
	
	return result;
}


std::ostream &operator<<(std::ostream &out, fraction f){
	std::string s;
	s = f.toString();
	out << s;
	return out;
}

std::istream& operator>>(std::istream &in, fraction &f){
	in >> f.numerator;
	in >> f.denominator;
	return in;
}


const fraction operator*(const fraction& rhs, const fraction& lhs){
		fraction f;
		f.denominator = rhs.denominator*lhs.denominator;
		f.numerator = rhs.numerator*lhs.numerator;
		f.reduce();	
		return f;
	};
const fraction operator/(const fraction& rhs, const fraction& lhs){
		fraction f;
		f.denominator = rhs.denominator*lhs.numerator;
		f.numerator = rhs.numerator*lhs.denominator;
		f.reduce();	
		return f;
	};
const fraction operator+(const fraction& rhs, const fraction& lhs){
		fraction f;
		f.numerator = ((rhs.numerator*lhs.denominator)+(lhs.numerator*rhs.denominator));
		f.denominator = (rhs.denominator*lhs.denominator);
		f.reduce();	
		return f;
	};
const fraction operator-(const fraction& rhs, const fraction& lhs){
		fraction f;
		f.numerator = ((rhs.numerator*lhs.denominator)-(lhs.numerator*rhs.denominator));
		f.denominator = (rhs.denominator*lhs.denominator);
		f.reduce();	
		return f;
	};
