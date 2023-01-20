Add
```
task loadFirestormRoboticsLibrary(type: Exec) {
    commandLine 'python', 'use.py'
}

build.dependsOn loadFirestormRoboticsLibrary
```
to `build.gradle` in your robot project. `use.py` will automatically check the library version and download it if necessary every time a build runs on wifi.  
From there, just `#include <FRL/whatever/whatever.hpp>` to use libraries.

Everything is kept under the namespace `frl` - theoretically. In practice almost nothing is. This is a Work In Progress.