#!/usr/bin/env python3
##
## EPITECH PROJECT, 2022
## compare_champ.py
## File description:
## compare_champ.py
##

import os

global SUCCESS
global FAILS
global MAYBE_CRASH

SUCCESS = 0
FAILS = 0
MAYBE_CRASH = 0

#For all file in ./champ with *.s extension we launch the command asm

def asm_champ():
    global SUCCESS, FAILS, MAYBE_CRASH
    for file in os.listdir("./champ"):
        if file.endswith(".s"):
            try :
                os.system("./asm ./champ/" + file)
            except:
                print("Error with " + file)
                MAYBE_CRASH += 1

#For all file in ./champ with *.cor extension we launch the command hexdump in a txt file

def my_hexdump_champ():
    global SUCCESS, FAILS, MAYBE_CRASH
    for file in os.listdir("./"):
        if file.endswith(".cor"):
            try :
                os.system("hexdump -C " + file + " > my_" + file + ".txt")
            except:
                print("No txt with " + file)

#For all file in ./champ with *.s extension we launch the command ref

def ref_champ():
    global SUCCESS, FAILS, MAYBE_CRASH
    for file in os.listdir("./champ"):
        if file.endswith(".s"):
            try :
                os.system("./ref ./champ/" + file)
            except:
                print("Error with " + file)
                MAYBE_CRASH += 1

#For all file in ./champ with *.cor extension we launch the command hexdump in a txt file

def ref_hexdump_champ():
    global SUCCESS, FAILS, MAYBE_CRASH
    for file in os.listdir("./"):
        if file.endswith(".cor"):
            try :
                os.system("hexdump -C " + file + " > ref_" + file + ".txt")
            except:
                print("No txt with " + file)

#For all file with ref_*.txt we launch the command diff with my_*.txt

def compare_hexdump():
    global SUCCESS, FAILS, MAYBE_CRASH
    for file in os.listdir("./"):
        if file.endswith(".txt") and file.startswith("my_"):
            try :
                if os.system("diff " + file + " ref_" + file[3:] + "> /dev/null") == 0:
                    SUCCESS += 1
                else:
                    FAILS += 1
            except:
                print("Error with " + file + " and ref_" + file[3:])
                MAYBE_CRASH += 1

#For all file with my_*.txt and ref_*.txt we delete the txt file and the cor file

def rm_txt_cor():
    global SUCCESS, FAILS, MAYBE_CRASH
    for file in os.listdir("./"):
        if file.endswith(".txt"):
            try :
                os.remove(file)
            except:
                print("Error remove " + file)
        if file.endswith(".cor"):
            try :
                os.remove(file)
            except:
                print("Error remove " + file)

def main():
    asm_champ()
    my_hexdump_champ()
    ref_champ()
    ref_hexdump_champ()
    compare_hexdump()
    rm_txt_cor()
    print("SUCCESS: " + str(SUCCESS))
    print("FAILS: " + str(FAILS))
    print("MAYBE_CRASH: " + str(MAYBE_CRASH))

main()
