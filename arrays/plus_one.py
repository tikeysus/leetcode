'''You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.'''

def array_to_int(digits):
    number = 0
    for i in range(len(digits)):
        number += digits[i] * (10 ** (len(digits) - i - 1)) 
    return number + 1

def increment_array(digits):
    n = len(digits) - 1
    carry = 1

    for i in range(n, -1, -1):
        total = digits[i] + carry
        digits[i] = total % 10
        carry = total // 10

    if carry:
        digits.insert(0, carry)

    return digits


