public class LongestUniqueSubstring{
	public static void main(String args[]){}
	
	public int lengthOfLongestSubstring(String s){
		int[] chars = new int[256]; 
		int left = 0; 
		int right = 0; 
		int max = 0; 

		while (right < s.length()){
			if (chars[s.charAt(right)] == 1){
				chars[s.charAt(left)] = 0; 
				left ++; 
			}

			else{
				chars[s.charAt(right)] = 1; 
				right ++; 
			}

			if (right - left > max){
				max = right - left; 
			}
		}

		return max; 
	}
}