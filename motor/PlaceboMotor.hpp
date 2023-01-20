/* Placebo Motor */

#include "BaseMotor.hpp"


/**
 @author Tyler Clarke
 @version 1.0
  
 * Placebo motor - all the functions are empty. Useful if you want to... uh... actually I have no clue what it's useful for, but it seems useful.
 */

class PlaceboMotor : public BaseMotor{
public: // Does NOTHING for now. Add printouts later, if necessary. It's a placebo!
    /**
     * Construct a new placebo motor. Does nothing.
     */
    PlaceboMotor (){
    }

    void SetPercent(double speed){
    }

    void SetP(double kP){
    }

    void SetI(double kI){
    }

    void SetD(double kD){
    }

    void SetF(double kF){
    }

    void SetOutputRange(double kPeakOF, double kPeakOR, double kNominalOF = 0, double kNominalOR = 0){
    }

    void SetPositionPID(double position){
    }

    void SetSpeedPID(double speed){
    }

    void SetInverted(bool invert){
    }

    bool IsAtZero(){
    }
};
