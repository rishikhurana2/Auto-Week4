/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RedPathway.h"

RedPathway::RedPathway() {
	AddSequential(new DriveForward(topBottomRed));
	AddSequential(new TurnLeftorRight(90));
	AddSequential(new DriveForward(RedDownwards));
	AddSequential(new TurnLeftorRight(90));
	AddSequential(new DriveForward(topBottomRed - PinkBlue));
	AddSequential(new TurnLeftorRight(90));
	AddSequential(new DriveForward(19.56));
}
