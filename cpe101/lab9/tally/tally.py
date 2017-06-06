import sys

def readfile(filex, column):
    sumtally = 0
    try:
       for line, linenum in enumerate(filex):
          columnnum = 0
          for floatstring in column:
             if comlumnnum != column:
                continue
             try:
                sumtally += float(floatstring)
             except:
                print linenum + ' not a number'
             columnnum += 1
          if columnnum < column:
             print linenum + ' out of range'
    except:
       print 'ERROR'
       exit()

       if __name__ = '__main__
