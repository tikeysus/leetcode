## Arrays 

- Prefix and Suffix arrays for except self type questions. 
- Modelling a 2D array as 1D. 
- If we only want to fill in values that fit a certain criteria while assigning all other array indeces the default value (whether that is 0 or -1), we can use functions like calloc or we can fill it in first with the default value and then invoke the algorithm. 

## Bit Manipulation 

- There is a pattern in the fact that a^a=0. 	
- ORs and ANDs can also be useful in assignments. 
- We can avoid using the pow operation unless we have to. For example, instead of saying 2**n, we can use (1 << n). 
- ANDing numbers in a certain range means considering the LEFTMOST bits of the first and last numbers. We look at the amount of on bits that are shared starting from the MSB.

## Sliding Window

- We can use while loops inside our for loops to ensure that the ideal conditions are met for the window to keep sliding.
