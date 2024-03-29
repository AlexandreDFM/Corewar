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
global MAYBE_CRASH

SUCCESS = 0
FAILS = 0
MAYBE_CRASH = 0

#For all file in ./error try with the program given in argument and test if the output is 84

def error_champ(char = "./asm"):
    global SUCCESS, FAILS, MAYBE_CRASH
    for file in os.listdir("./error"):
        if file.endswith(".s"):
            try :
                i = os.system(char + " ./error/" + file + "> /dev/null")
                if (i == 21504):
                    print("\033[01m\033[30m\033[04mSUCCES :\033[0m\033[32m with " + file + "\033[0m")
                    SUCCESS += 1
                elif (i == 35584):
                    print("\033[01m\033[30m\033[04mFAIL :\033[0m\033[31m Crash ? with " + char + " " + file + "\033[0m")
                    MAYBE_CRASH += 1
                else :
                    print("\033[01m\033[30m\033[04mFAIL :\033[0m\033[31m with " + file + "\033[0m")
                    FAILS += 1
            except:
                print("\033[31mError Crash ? with " + char + " " + file + "\033[0m")
                MAYBE_CRASH += 1
    for file in os.listdir("./"):
        if file.endswith(".cor"):
            try :
                os.remove(file)
            except:
                print("Error remove " + file)
    print("SUCCESS : " + str(SUCCESS))
    print("FAILS : " + str(FAILS))
    print("MAYBE CRASH : " + str(MAYBE_CRASH))

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
    else :
        print("Error with argument")
        exit(84)

main(len(sys.argv), sys.argv)
