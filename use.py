from requests import get
import os


r = get("https://firestorm-robotics-code.github.io/FirestormRoboticsLibrary/exports", timeout=1)
try:
    os.mkdir("src/main/include/FRL")
except:
    pass
for x in r.text.split("\n"):
    if len(x) == 0:
        continue
    if x[0] == "D":
        os.mkdir("src/main/include/FRL/" + x[1:])