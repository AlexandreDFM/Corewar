#!/usr/bin/env python3
##
## EPITECH PROJECT, 2022
## error_handling.py
## File description:
## error_handling.py
##

import os
import sys

global SUCCESS
global FAILS

SUCCESS = 0
FAILS = 0

#For all file in ./error try with the program given in argument and test if the output is 84

def error_champ(char = "./asm"):
    global SUCCESS, FAILS
    for file in os.listdir("./error"):
        if file.endswith(".s"):
            try :
                if (os.system(char + " ./error/" + file) == 21504):
                    SUCCESS += 1
                else :
                    FAILS += 1
            except:
                print("Error with " + char + " " + file)
                FAILS += 1
    for file in os.listdir("./"):
        if file.endswith(".cor"):
            try :
                os.remove(file)
            except:
                print("Error remove " + file)
    print("SUCCESS : " + str(SUCCESS))
    print("FAILS : " + str(FAILS))

def main(argc, argv):
    if argc == 2:
        try :
            if (os.system("find " + argv[1] + " > /dev/null") == 0):
                error_champ("./" + argv[1])
            else :
                print("Error with " + argv[1])
                exit(84)
        except:
            print("Error with " + argv[1])
            exit(84)
    elif argc == 1:
        try :
            if (os.system("find asm > /dev/null") == 0):
                error_champ()
            else :
                print("Error with asm")
                exit(84)
        except:
            print("Error with asm")
            exit(84)
        error_champ()
    else :
        print("Error with argument")
        exit(84)

main(len(sys.argv), sys.argv)
