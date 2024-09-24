def min_extra_char(s, dictionary):
	array = [] 
	count = 0
	left = 0
	right = 1
	while (right <= len(s)  and right > left):
		if (s[left:right] in dictionary):
			right += 1 
			array.append((left, right - 1))
		else:
			count += 1
			right += 1
		if (right == len(s) and array[left:right] in dictionary):
			array.append((left, right - 1))
		elif (right == len(s) and array[left:right] not in dictionary):
			right = left + 1
			right += 1
			left += 1
	print(array)
	return count

print(min_extra_char("scode", ["leet", "code", "leetcode"]))