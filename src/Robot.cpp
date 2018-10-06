/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

//#include "Commands/ExampleCommand.h"
//#include "Commands/MyAutoCommand.h"

class Robot : public frc::TimedRobot {
public:
	void RobotInit() override {
//		m_chooser.AddDefault("Default Auto", &m_defaultAuto);
		chooser.AddObject("Blue Pathway", std::shared_ptr<BluePathways>(new BluePathways()));
		chooser.AddObject("Middle Bottom", std::shared_ptr<MiddleBottom>(new MiddleBottom()));
		chooser.AddObject("Middle Top", std::shared_ptr<MiddleTop>(new MiddleTop()));
		chooser.AddObject("Pink Pathway", std::shared_ptr<PinkPathways>(new PinkPathways()));
		chooser.AddObject("Red Downward", std::shared_ptr<RedDownwardPathway>(new RedDownwardPathway()));
		chooser.AddObject("Red Pathway", std::shared_ptr<RedPathway>(new RedPathway()));
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
	}

	/**
	 * This function is called once each time the robot enters Disabled
	 * mode.
	 * You can use it to reset any subsystem information you want to clear
	 * when
	 * the robot is disabled.
	 */
	void DisabledInit() override {}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to
	 * the
	 * chooser code above (like the commented example) or additional
	 * comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		std::string autoSelected = frc::SmartDashboard::GetString(
				"Auto Selector", "Default");
		std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		std::string autoString = chooser.GetName();
			autonomousCommand = chooser.GetSelected();

		if (autonomousCommand != nullptr) {
			autonomousCommand->Start();
		}
		if (autoString == "Mid") {
			if (gameData[0] == 'L') {
				autonomousCommand.reset(new MiddleTop());
			} else {
				autonomousCommand.reset(new MiddleBottom());
			}
		}
		if (autoString == "Left") {
			if (gameData[0] == 'R'){
				autonomousCommand.reset(new RedPathway());
			} else {
				autonomousCommand.reset(new PinkPathways());
			}
		}
		if (autoString == "Right") {
			if (gameData[0] == 'L') {
				autonomousCommand.reset(new RedDownwardPathway());
			} else {
				autonomousCommand.reset(new BluePathways());
			}
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
			autonomousCommand = nullptr;
		}
	}

	void TeleopPeriodic() override { frc::Scheduler::GetInstance()->Run(); }

	void TestPeriodic() override {}

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	std::unique_ptr<frc::Command> autonomousCommand;
//	ExampleCommand m_defaultAuto;
//	MyAutoCommand m_myAuto;
	//frc::SendableChooser<frc::Command*> m_chooser;
	frc::SendableChooser<std::shared_ptr<frc::Command>> chooser;
};
//
//START_ROBOT_CLASS(Robot)
