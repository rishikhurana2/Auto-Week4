/*
 * WVPIDController.h
 *
 *  Created on: Oct 5, 2018
 *      Author: Rishi Khurana
 */

#ifndef SRC_UTILITIES_WVPIDCONTROLLER_H_
#define SRC_UTILITIES_WVPIDCONTROLLER_H_

#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class WVPIDController {
public:
	WVPIDController(double Kp, double Ki, double Kd, double setPoint,
	bool integralThreshold);
	double Tick(double measuredValue);
	void SetSetPoint(double setPoint);
	double GetSetPoint();
	void SetKp(double Kp);
	double GetKp();
	void SetKi(double Ki);
	double GetKi();
	void SetKd(double Kd);
	double GetKd();
	double GetError();
	double GetLastPWM();

private:

	double Kp;
	double Ki;
	double Kd;
	double setPoint;
	bool integralThreshold;
	double lastPWM;
	double error;
	double previousError;
	double integral;
};

#endif
};

#endif /* SRC_UTILITIES_WVPIDCONTROLLER_H_ */