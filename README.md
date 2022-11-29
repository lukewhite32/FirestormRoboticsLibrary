## This is a very minimal set of libraries for Firestorm Robotics.
It's really very simple. Just configure your build script (in a robot project) to run `use.py` and it handles the rest.

Include `FRL/motor/SparkMotor.hpp` for SparkMotors (polymorphic wrapper around SparkMax)  
Include `FRL/motor/TalonSRXMotor.hpp` for SparkMotors (polymorphic wrapper around TalonSRX)  
It doesn't come with vendor libraries; supply Phoenix and Revlib yourself.
