'''Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.'''

def needle_in_hay(haystack, needle):
    if needle == haystack:
        return 0
    start = 0
    end = len(needle)
    while end <= len(haystack):
        if needle in haystack[start:end]:
            return start 
        start += 1
        end += 1
    return -1 
    
