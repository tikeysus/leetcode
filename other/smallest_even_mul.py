'''Given a positive integer n, return the smallest positive integer that is a multiple of both 2 and n.'''

def smallest_even_multiple(n):
    i = 2
    while i % n != 0:
        i += 2
    return i 
