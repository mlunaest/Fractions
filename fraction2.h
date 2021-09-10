#ifndef FRACTION2_H
#define FRACTION2_H
#include <string>
#include <iostream>
#include <sstream>

class fraction{

	int numerator;
	int denominator;
	
	public:	
		fraction();//constructor with no parameters
		fraction(int num, int denum); //the constructor with parameters
		fraction(const fraction &obj);//copy constructor
		void reduce(void);
		void f_print(void);
		friend bool operator== (const fraction &a, const fraction &b);
		friend bool operator!= (const fraction &a, const fraction &b);
		friend bool operator< (const fraction &a, const fraction &b);
		friend bool operator> (const fraction &a, const fraction &b);
		friend bool operator<= (const fraction &a, const fraction &b);
		friend bool operator>= (const fraction &a, const fraction &b);
		operator double();
		std::string toString();
		friend std::ostream& operator<<(std::ostream &out, fraction f);
		friend std::istream& operator>>(std::istream &in, fraction &f); 
		
		friend const fraction operator*(const fraction& rhs, const fraction& lhs);
		friend const fraction operator/(const fraction& rhs, const fraction& lhs);
		friend const fraction operator+(const fraction& rhs, const fraction& lhs);
		friend const fraction operator-(const fraction& rhs, const fraction& lhs);
		
		
};

#endif
