def is_lower_101(x):
   if ord(x) >= 97 and ord(x) <= 122:
      return True
   else:
      return False

def char_rot_13(x):
        c = ord(x)
        if c >= ord('a') and c <= ord('z'):
            if c > ord('m'):
                c -= 13
            else:
                c += 13
        elif c >= ord('A') and c <= ord('Z'):
            if c > ord('M'):
                c -= 13
            else:
                c += 13
        return chr(c)
