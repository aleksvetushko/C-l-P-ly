import driver

def letter(row, col):
    if (col <= 9):
        return 'X'
    else:
        return 'O'

if __name__ == '__main__':
    driver.comparePatterns(letter)
