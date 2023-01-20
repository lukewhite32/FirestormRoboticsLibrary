from requests import get
import os


r = get("https://firestorm-robotics-code.github.io/FirestormRoboticsLibrary/exports", timeout=1)
try:
    os.mkdir("src/main/include/FRL")
except:
    pass
if r.status_code == 200:
    for x in r.text.split("\n"):
        if len(x) == 0:
            continue
        if x[0] == "D":
            try:
                os.mkdir("src/main/include/FRL/" + x[1:])
            except:
                pass
        if x[0] == "F":
            f = get("https://firestorm-robotics-code.github.io/FirestormRoboticsLibrary/" + x[1:])
            if f.status_code == 200:
                open("src/main/include/FRL/" + x[1:], "w+").write(f.text)
            else:
                print("Couldn't download", x[1:] + "!", "This is probably because somebody wrote a malformed dependency line. Please submit a bug report.\nNote: This is not a breaking issue; if your code (or another file you're using) doesn't depend on", x[1:], "you're fine.")