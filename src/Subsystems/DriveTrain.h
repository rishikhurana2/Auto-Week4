/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "math.h"

class DriveTrain : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TalonSRX* left;
	TalonSRX* right;
	//ADXRS450_Gyro* gyro;
	double circumference = 6 * M_PI; //diameter = 6 inches
public:
	DriveTrain();
	void InitDefaultCommand();
	void tankDrive(double leftVal, double rightVal);
	//void arcadeDrive(double moveVal, double rotateVal);
	double Limit(double num, double max);
	//double getAngle();
	//double getSpeed();
	//void gyroReset();
	double leftDistance(); //inches
	double rightDistance(); //inches
	void resetEncoders();
	//void gyroCalibrate();

};

