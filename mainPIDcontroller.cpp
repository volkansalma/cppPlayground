#include <iostream>
#include "pid_controller.h"

using namespace std;

int main()
{
	PID_Controller myPid;
	
	myPid.setParameters(0.2, 0.05, 0.0001, 0.02, 50, -50);
	
	for(int i = 0; i < 50; i++)
	{
		cout<<myPid.calculate(i, 10)<<endl;
	}
	
	return 0;
}