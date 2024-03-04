'''
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
'''

def max_area(height):
    max = 0
    for i in range(len(height)):
        for j in range(i + 1, len(height)):
            if (j + 1 - (i + 1)) * (min(height[i], height[j])) > max:
                max = (j + 1 - (i + 1)) * (min(height[i], height[j]))
    return max

#times out for large inputs, have to revisit this one. 

def max_area(height):
    max = 0
    empty = dict()
    sorted_height = sorted(height)
    for i in range (len(sorted_height)):
        if sorted_height[i] in empty:
            pass 
        empty[sorted_height[i]] = height.index(sorted_height[i])
    return empty 

print(max_area([1,8,6,2,5,4,8,3,7]))