/* Placebo Motor */

#include "BaseMotor.hpp"


class PlaceboMotor : public BaseMotor{
public: // Does NOTHING for now. Add printouts later, if necessary. It's a placebo!
    PlaceboMotor (int canID){
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
};
