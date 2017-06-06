import sys

def cmdline(x):
    x = sys.argv
    for i in x:
        print [x.index(i), i]

cmdline(sys.argv)
