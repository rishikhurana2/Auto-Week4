/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <memory>
#include <string>
#include <iostream>

#include <Commands/Command.h>

//#include "Subsystems/Catcher.h"
//#include "OI.h"
#include "Subsystems/DriveTrain.h"
//#include "Subsystems/Arm.h"
//#include "Subsystems/Camera.h"
//#include "Subsystems/Lift.h"

class CommandBase : public frc::Command {

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void initialize();

	// Create a single static instance of all of your subsystems
	static DriveTrain* drive;

};


