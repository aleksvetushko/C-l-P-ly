import driver

def letter(row, col):
    if (row >= 2 and row <= 6):
        if (row == 2 or row == 3):
            if (col >= 4 and col <= 9):
                return 'Z'
            else:
                return 'T'
        elif (row == 4 or row == 5):
            if (col == 4 or col == 5 or col == 6):
                return 'Z'
            elif (col == 7 or col == 8 or col == 9):
                return 'X'
            elif (col == 10 or col == 11 or col == 12):
                return 'B'
            else:
                return 'T'
        elif (row == 6):
            if (col >= 7 and col <= 12):
                return 'B'
            else:
                return 'T'
    else:
        return 'T'

if __name__ == '__main__':
    driver.comparePatterns(letter)
