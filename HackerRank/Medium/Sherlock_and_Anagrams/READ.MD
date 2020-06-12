Problem Description
	Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. 
	Given a string, find the number of pairs of substrings of the string that are anagrams of each other.
	
	For example 's = mom', the list of all anagrammatic pairs is [m, m], [mo, om] 
	at positions [[0],[2]], [[0, 1], [1, 2]] respectively.
	
Function Description
	Complete the function sherlockAndAnagrams in the editor below. 
	It must return an integer that represents the number of anagrammatic pairs of substrings in .

	sherlockAndAnagrams has the following parameter(s):
	- s: a string
	
Input Format
	The first line contains an integer 'q', the number of queries.
	Each of the next 'q' lines contains a string 's' to analyze.
	
Output Format
	For each query, return the number of unordered anagrammatic pairs.
	
Link - https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem	
	
	
	
About the Code:
	Big-O
    	O(n2) for Time Complexity
    	O(n2) for Space Complexity
    Idea Behind the algorithm
		Stage 1	
    	The function build map table that contains char set of sub-string and its occurance.
        char set of sub-string is denoted by array<int, 26> which represent occurance of each alphabet.
        The map uses 'char set of sub-string' as a key element and its frequency as an value element.
        The reason fixed size 'array' is used instead of...
        	- Summation of decimal value of alphabet
              There is possility of same sum value with different alphabet 
			  combination with same length and different length.
            - Comparing Two sorted Sub-String
              It will spend too much time for sorting process.
            - Use find function to check
              It will spend too much time for sorting process.
		Every time the array is updated, the map is updated also.
        This process allows time complexity of algorithm changes from
        	O(n3) to O(n2)
        For example, there is 'aba' and array<int, 5> with 
            1st external iteration
                1st inner iteration...
                    1 0 0 0 0       -> array
                    1 0 0 0 0 - 1   -> map
                2st inner iteration...
                    1 1 0 0 0       -> array
                    1 0 0 0 0 - 1   -> map
                    1 1 0 0 0 - 1   -> map
                3rd inner iteration...
                    2 1 0 0 0       -> array
                    1 0 0 0 0 - 1   -> map
                    1 1 0 0 0 - 1   -> map
                    2 1 0 0 0 - 1   -> map
            2nd external iteration
                1st inner iteration...
                    0 1 0 0 0       -> array
                    1 0 0 0 0 - 1   -> map
                    0 1 0 0 0 - 1   -> map
                    1 1 0 0 0 - 1   -> map
                    2 1 0 0 0 - 1   -> map
                2st inner iteration...
                    1 1 0 0 0       -> array
                    1 0 0 0 0 - 1   -> map
                    0 1 0 0 0 - 1   -> map
                    1 1 0 0 0 - 2   -> map
                    2 1 0 0 0 - 1   -> map
            3rd external iteration
                1st inner iteration...
                    1 0 0 0 0       -> array
                    1 0 0 0 0 - 2   -> map
                    0 1 0 0 0 - 1   -> map
                    1 1 0 0 0 - 2   -> map
                    2 1 0 0 0 - 1   -> map
            Final Result of map container
                1 0 0 0 0 - 2   -> a, a
                0 1 0 0 0 - 1   -> b
                1 1 0 0 0 - 2   -> ab, ba
                2 1 0 0 0 - 1   -> aba
				
				
		Stage 2
	    Now, From the map we need to calculate number of orrurance.
	    To minimize the unnecessary calculation, check only if the occurance is bigger than 1.
	    Formula 'n(n-1)/2' denotes number of pair that can be form form 
	    the 'n' element sets, where 'n' is equal to number of occruance.