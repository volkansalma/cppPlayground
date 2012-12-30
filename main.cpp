#include <iostream>
#include "template.h"

using namespace std;

int main()
{
	calc<double> calculator;
	
	cout<<calculator.add(3, 5)<<endl;
	cout<<calculator.substract(3, 5)<<endl;
	cout<<calculator.multiply(3, 5)<<endl;
	cout<<calculator.divide(3, 5)<<endl;
	

	return 0;
}