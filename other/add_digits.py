'''Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.'''

def add_digits(n):
    if n // 10 == 0:
        return n 
    while n // 10 != 0:
        n = n // 10 + n % 10
    return n
