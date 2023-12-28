"""
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.
"""

def find_repeated_dna_sequences(sequences):
    window_start = 0
    window_end = 9
    frequencies = {}
    result = []

    while window_end < len(sequences):
        if sequences[window_start:window_end + 1] in frequencies:
            frequencies[sequences[window_start:window_end + 1]] += 1
        else:
            frequencies[sequences[window_start:window_end + 1]] = 1
        window_start += 1
        window_end += 1
    
    for sequence, frequency in frequencies.items():
        if frequency > 1:
            result.append(sequence)
    
    return result