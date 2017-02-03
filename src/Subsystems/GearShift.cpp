// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CANTalon.h"


#include "GearShift.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

GearShift::GearShift() : Subsystem("GearShift") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    gearTalon = RobotMap::gearShiftGearTalon;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void GearShift::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void GearShift::SetTalonInit(){
	std::cout << "Initialize\n";
	int profile=0;
	gearTalon->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
	gearTalon->SetControlMode(frc::CANSpeedController::ControlMode::kPosition);
	gearTalon->ConfigNominalOutputVoltage(+0.0,-0.0);
	gearTalon->ConfigPeakOutputVoltage(+3.0,-3.0);//3.0 -3.0
	gearTalon->SetSensorDirection(false);
	gearTalon->SelectProfileSlot(profile);
	gearTalon->SetPosition(0);
	gearTalon->SetAllowableClosedLoopErr(0);
	gearTalon->SetPID(0.1,0,10,0);//P:.1 D:10
	gearTalon->SetVoltageRampRate(1);

}
void GearShift::MoveLeft(){
	std::cout << "Move Left\n";
	gearTalon->Set(3);

}
void GearShift::MoveCenter(){
	std::cout << "Move Center\n";
	gearTalon->Set(0);
}
void GearShift::MoveRight(){
	std::cout << "Move Right\n";

	gearTalon->Set(-3);
}
void GearShift::PrintPosition(){
	std::cout << gearTalon->GetPosition() << " " << gearTalon->GetClosedLoopError() << "\n";
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

