#ifndef _PID_CONTROLLER_H_
#define _PID_CONTROLLER_H_

class PID_Controller
{
public:
	PID_Controller(float Kp = 0.5, float Ki = 0.2, float Kd = 0, float dt = 0.02, 
				   float outputHighLimit = 100, float outputLowLimit = -100);
				   
	~PID_Controller();
	void reset();
	void setParameters(float Kp, float Ki, float Kd, float dt, 
				       float outputHighLimit, float outputLowLimit);
				  
	float calculate(float refValue, float actualValue);
private:
	float mKp;
	float mKi;
	float mKd;
	float mOutputHighLimit;
	float mOutputLowLimit;
	
	float mAccErrIntegral;
	float mPrevError;
	float mDt;
	float mError;
	float mOutput;
	float mDerivativeErr;
};


#endif
