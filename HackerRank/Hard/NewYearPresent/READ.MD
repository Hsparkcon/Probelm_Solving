Problem Description
	Nina received an odd New Year's present from a student: 
	a set of 'n' unbreakable sticks. 
	Each stick has a length 'l', and the length of the 'ith' stick is 'l_i-1'. 
	
	Deciding to turn the gift into a lesson, Nina asks her students the following:
	How many ways can you build a square using exactly '6' of these unbreakable sticks?

Note: 
	Two ways are distinct if they use at least one different stick. 
	As there are  choices of sticks, we must determine which combinations of sticks can build a square.
	
Input Format:
	The first line contains an integer 'n', denoting the number of sticks. 
	The second line contains 'n' space-separated integers l_0, l_1, ...... l_n-2, l_n-1
	describing the length of each stick in the set.
	
Output Format:
	On a single line, print an integer representing the number of ways 
	that 6 unbreakable sticks can be used to make a square.
	
Link - https://www.hackerrank.com/challenges/newyear-present/problem



About Code:
	This problem must be started with a brute-force algorithm.
	It is not becasue the question is hard, it is becasue human readable testcase given by the question
	does not cover entire requirement.
	It must be started with the brute-force algorithms to build testcases that covers every case for the problem.
	