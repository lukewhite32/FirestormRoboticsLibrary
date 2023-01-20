This is a very simple set of C++ libraries for Firestorm Robotics (FRC 6341) and indeed anybody else. Written by the coders at Firestorm Robotics.  
Support for Windows and MacOS not guaranteed - we're largely a Linux team

To use:
Download [use.py](https://firestorm-robotics-code.github.io/FirestormRoboticsLibrary/use.py) and place it in your robot project's root directory (NOT under src!) and add
```
task loadFirestormRoboticsLibrary(type: Exec) {
    commandLine 'python', 'use.py'
}

build.dependsOn loadFirestormRoboticsLibrary
```
to `build.gradle` in your robot project.  
`use.py` will automatically check the library version and download it if necessary every time a build runs on wifi.  
From there, just `#include <FRL/whatever/whatever.hpp>` to use libraries.

Everything is kept under the namespace `frl` - theoretically. In practice almost nothing is. This is a Work In Progress.