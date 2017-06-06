import driver

def letter(row, col):
    if (col == row or col + row == 6):
        return 'X'
    else:
        return 'O'

if __name__ == '__main__':
    driver.comparePatterns(letter)
