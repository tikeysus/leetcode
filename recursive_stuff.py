def list_count(items): 
    if len(items) == 0:
        return 0 
    if len(items) == 1:
        return items[0]
    return items[0] + list_count(items[1:])
    
def fact(num):
    if num < 0:
        return None 
    elif num == 0 or num == 1:
        return 1
    return num * fact(num - 1)

def summer(num):
    if len(num) == 0:
        return 0 
    if len(num) == 1:
        return num[0]
    return int(num[0]) + int(summer(num[1:])) 

def harmonic_sum(n):
    if n <= 0:
        return None 
    elif n == 1:
        return 1  
    return 1/n + harmonic_sum(n - 1)

    
def power(a, b):
    if b == 0:
        return 1
    if b == 1:
        return a 
    return a * power(a, b - 1)


def count(items, target):
    if len(items) == 0:
        return 0 
    if len(items) == 1 and target in items:
        return 1
    elif len(items) == 1 and target not in items:
        return 0
    if items[0] == target: return 1 + count(items[1:], target)
    else: return count(items[1:], target)

def integer_sum(items):
    if len(items) == 0:
        return 0 
    if len(items) == 1 and type(items[0]) == int:
        return items[0] + integer_sum(items[1:])
    elif len(items) == 1 and type(items[0]) != int or (items[0] is True):
        return integer_sum(items[1:])
    elif len(items) > 1 and type(items[0]) == int:
        return items[0] + integer_sum(items[1:])
    elif len(items) > 1 and type(items[0]) != int:
        return integer_sum(items[1:])

def is_palindrome(word):
    if len(word) == 0 or len(word) == 1:
        return True 
    if word[0] == word[-1]:
        return is_palindrome(word[1:-1])
    return False 

def string_reverse(word):
    if len(word) == 0:
        return ''
    elif len(word) == 1:
        return word 
    elif len(word) == 2:
        return word[1] + word[0]
    return string_reverse(word[1:]) + word[0]

def string_length(word):
    if word == '':
        return 0 
    return 1 + string_length(word[1:])

def countdown(n):
    if n == 0:
        return '0'
    return f'{n}' + countdown(n - 1)

def nested_list(array):
    if not array:
        return [] 
    if type(array[0]) == list:
        return nested_list[0] + nested_list(array[1:])
    return array[0] + nested_list(array[1:])

def summation(n):
    if n == 0:
        return 0 
    if n == 1:
        return 1
    return n + summation(n - 1)

def odd_sum(nums):
    if not nums:
        return 0 
    if nums[0] % 2 == 0:
        return odd_sum(nums[1:])
    else:
        return nums[0] + odd_sum(nums[1:])

def log(n):
    if n <= 0:
        return None
    if n == 1:
        return 0 
    elif n == 10:
        return 1 
    return 1 + log(n // 10)

def sum_odd_sub_even(nums):
    if not nums:
        return 0 
    if nums[0] % 2 == 1:
        return nums[0] + sum_odd_sub_even(nums[1:])
    if nums[0] % 2 == 0:
        return -nums[0] + sum_odd_sub_even(nums[1:])
    
def multiply(a, x):
    if x == 0:
        return 0 
    elif x == 1:
        return a 
    return a + multiply(a, x - 1)

def only_odd_digits(n):
    if n // 10 == 0 and (n % 10) % 2 == 1:
        return True 
    if n % 2 == 0:
        return False 
    elif n % 2 == 1:
        return only_odd_digits(n // 10)
    
def colour_trio(colours):
    colour_archive = {'rr': 'r', 'bb': 'b', 'yy': 'y',
                      'ry': 'b', 'rb': 'y',
                      'br': 'y', 'by': 'r',
                      'yr': 'b', 'yb': 'r'}
    
    colour_list = list(colours)
    
    if len(colour_list) == 1:
        return colour_list[0]
    
    for i in range(len(colour_list) - 1):
        colour_list[i] = colour_archive[colour_list[i] + colour_list[i + 1]]
    
    colour_list.pop()

    return colour_trio(colour_list)
Hello world
