#include "pid_controller.h"

PID_Controller::PID_Controller(float Kp, float Ki, float Kd, float dt, 
							   float outputHighLimit, float outputLowLimit)
{
	mKp = Kp;
	mKi = Ki;
	mKd = Kd;
	mOutputHighLimit = outputHighLimit;
	mOutputLowLimit = outputLowLimit;
	mDt = dt;
	
	mAccErrIntegral = 0;
	mPrevError = 0;
	mError = 0;
	mOutput = 0;
	mDerivativeErr = 0;
}

PID_Controller::~PID_Controller()
{
	;
}

void PID_Controller::reset()
{
	mAccErrIntegral = 0;
	mPrevError = 0;
	mError = 0;
	mOutput = 0;
	mDerivativeErr = 0;
}

void PID_Controller::setParameters(float Kp, float Ki, float Kd, float dt, 
								   float outputHighLimit, float outputLowLimit)
{
	mKp = Kp;
	mKi = Ki;
	mKd = Kd;
	mOutputHighLimit = outputHighLimit;
	mOutputLowLimit = outputLowLimit;
	mDt = dt;
}
	

float PID_Controller::calculate(float refValue, float actualValue)
{
	mError = refValue - actualValue;
	
	mAccErrIntegral += mError * mDt;
	mDerivativeErr = (mError - mPrevError)/mDt;
	
	mOutput = mKp * mError + mKi * mAccErrIntegral + mKd * mDerivativeErr;
	
	if(mOutput > mOutputHighLimit)
	{
		mOutput = mOutputHighLimit;
	}
	else if(mOutput < mOutputLowLimit)
	{
		mOutput = mOutputLowLimit;
	}
	
	mPrevError = mError;
	
	return mOutput; 
}
