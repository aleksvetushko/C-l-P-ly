import sys

def readfile(filex):
    try:
       for line in filex:
          linesum = 0.0
          for floatstring in line:
             try:
                linesum += float(floatstring)
             except:
                print 'ERROR'
             print linesum
    except:
       print 'ERROR'
       exit
