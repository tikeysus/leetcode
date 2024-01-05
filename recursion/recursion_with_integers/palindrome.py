'''Given an integer x, return true if x is a 
palindrome
, and false otherwise.'''

def is_palindrome(x):
    x = str(x)
    return x == x[::-1]
    

    
    


