def groups_of_three(x):
    sub = [] ; result = []
    for i in x:
        sub += [i]
        if len(sub) == 3: result += [sub] ; sub = []
    if sub: result += [sub]
    return result
