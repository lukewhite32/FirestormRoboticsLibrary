/* By Luke White and Tyler Clarke
    Custom swerve module library using PIDController.
*/
// Note: This and PIDController.hpp need some more cleanup work.

#pragma once

#include "SparkMax.hpp"
#include <ctre/Phoenix.h>
#include <iostream>
#include "motor/PIDController.hpp"


class SwerveModule {
    BaseMotor* speed;
    BaseMotor* direction;
    PIDPositionController* directionController;
    CANCoder* cancoder;

    double curPercent; // So multiple commands can alter speed
    
    bool isLinked = false;  
   
    SwerveModule* linkSwerve;

    double encoderOffset; // Being CTRE their calibration code doesn't work. Like, at all. So this is the "custom" version.

public:
    SwerveModule(BaseMotor* speedMotor, BaseMotor* directionMotor, int CanCoderID, double offset, bool speedInverted=false, bool direcInverted=false) {
        encoderOffset = offset;
        std::cout << "Swerve: " << speedID << ", " << directionIdentifier << ", " << CanCoderID << ", " << roll << std::endl;
        speed = speedMotor;
        direction = directionMotor;
        cancoder = new CANCoder {CanCoderID};

        directionController = new PIDPositionController (direction);
        directionController -> constants.P = 0.0005;
        //directionController -> constants.I = 0.0001;
        directionController -> constants.MaxOutput = 0.2;
        directionController -> constants.MinOutput = -0.2;
        directionController -> SetCircumference(4096);
        
        if (speedInverted) {
            speed -> setInverted(true);
        }
        else{
            speed -> setInverted(false);
        }
        if (direcInverted) {
            direction -> setInverted(true);
        }
        else{
            direction -> setInverted(false);
        }
    }
    
    void Link(SwerveModule* LinkSwerve) {
        isLinked = true;           
        linkSwerve = LinkSwerve; 
    }

    void SetDirection(double targetPos) {
        directionController -> SetPosition(targetPos);
        directionController -> Update(GetAbsoluteCANCoderPos());
        if (isLinked){
            linkSwerve -> SetDirectionAngle(targetPos);
        }
    }

    void MovePercent(double spd, bool followLink = true){
        curPercent += spd;
        if (isLinked && followLink){
            linkSwerve -> MovePercent(spd);
        }
    }

    void ApplySpeed(){
        speed -> SetPercent(curPercent);
        curPercent = 0; // Velocity ain't "sticky", this is a safety thing
        if (isLinked){
            linkSwerve -> ApplySpeed();
        }
    } 

    long GetDirection() {
        return smartLoop(cancoder -> GetAbsolutePosition() - encoderOffset);
    }
};