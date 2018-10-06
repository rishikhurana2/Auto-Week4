/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
left(new TalonSRX(LEFTMOTOR)), right(new TalonSRX(RIGHTMOTOR)), gyro(new ADXRS450_Gyro())
{}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

}
double DriveTrain::Limit(double num, double max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

void DriveTrain::tankDrive(double leftVal, double rightVal) {
	left->Set(ControlMode::PercentOutput, DriveTrain::Limit(-leftVal, 1.0));
	right->Set(ControlMode::PercentOutput, DriveTrain::Limit(-rightVal, 1.0));
}

void DriveTrain::resetEncoders(){
	left->SetSelectedSensorPosition(0,0,10);
	right->SetSelectedSensorPosition(0,0,10);
}


double DriveTrain::leftDistance() { //inches

	double test = left->GetSensorCollection().GetPulseWidthPosition();
	double relativePosition = left->GetSensorCollection().GetQuadraturePosition(); // Return ticks

	relativePosition = ((relativePosition) / 4096) * circumference; // 4096 ticks per revolution
	//cout << "Abs: " << test << endl;
	test = ((test)/ 4096) * circumference;

	//cout << "Start: " << startAbsTicks << endl;
	//cout<< "Relative Position: " << relativePosition <<std::endl;
	//cout<< "Absolute Position: " << test <<std::endl;

	return relativePosition;
}

double DriveTrain::rightDistance() { //inches

	// double relativePosition = (double) (right->GetSensorCollection().GetPulseWidthPosition()); This also works, but I don't know what is different
	double relativePosition = -(right->GetSensorCollection().GetQuadraturePosition()); // Negative sign makes sure that forwards is positive and backwards is negative
	relativePosition = (relativePosition / 4096) * circumference; // 4096 ticks per revolution
	// std::cout<< "Right Wheel Relative Position: " << relativePosition << std::endl;
	return relativePosition;


}
void DriveTrain::gyroReset() {
	gyro->Calibrate();
}

double DriveTrain::getAngle() {
	double angle = gyro->GetAngle();
	//-180 to 180
	while (angle > 180) {
		angle -= 360;
	}
	while (angle < -180) {
		angle += 360;
	}
	return angle;
}
