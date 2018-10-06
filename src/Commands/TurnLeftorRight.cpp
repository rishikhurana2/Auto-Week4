/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/TurnLeftorRight.h>

TurnLeftorRight::TurnLeftorRight(double anglePoint) :
anglePID(new WVPIDController(0.02, 0, 0, angpoint, false))
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::drive);
	angpoint = anglePoint;
	power = 0;
	angleSpeed = 0;
}

// Called just before this Command runs the first time
void TurnLeftorRight::Initialize() {
	CommandBase::drive->gyroReset();
}

// Called repeatedly when this Command is scheduled to run
void TurnLeftorRight::Execute() {
	angleSpeed = 0.5;
	power = anglePID->Tick(CommandBase::drive->getAngle());
	if (angpoint < 0) {
		CommandBase::drive->tankDrive(power-0.25, 0.1 + power);
	}
	if (angpoint > 0) {
		CommandBase::drive->tankDrive(0.1 + power, power-0.25);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnLeftorRight::IsFinished() {
	return (CommandBase::drive->getAngle() >= angpoint);
}

// Called once after isFinished returns true
void TurnLeftorRight::End() {
	CommandBase::drive->tankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnLeftorRight::Interrupted() {

}
