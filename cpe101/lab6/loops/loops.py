def for_version(items):
   result = []
   for i in range(len(items) - 1, -1, -1):
      result.append(items[i])
   return result

def while_version(items):
   result = []
   i = len(items)
   while len(result) < len(items):
      result.append(items[i - 1])
      i -= 1
   return result
   pass
