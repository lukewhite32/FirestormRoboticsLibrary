## Add everything to whatever robot project this is currently in
import os


os.system("rm -rf src/main/include/FRL")
os.mkdir("src/main/include/FRL")
os.system("cp -r " + os.path.dirname(os.path.realpath(__file__)) + "/motor src/main/include/FRL") ## About half way THANKS STACKOVERFLOW
