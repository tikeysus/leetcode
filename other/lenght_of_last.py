'''Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.'''

def lenght_of_last_word(word):
    return len((word.split())[-1]) 
