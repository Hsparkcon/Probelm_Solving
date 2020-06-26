Problem Description
	It's New Year's Day and everyone's in line for the Wonderland rollercoaster ride! 
	There are a number of people queued up, and each person wears a sticker indicating their initial position in the queue. 
	Initial positions increment by 1 from 1 at the front of the line to 'n' at the back.
	
	Any person in the queue can bribe the person directly in front of them to swap positions. 
	If two people swap positions, they still wear the same sticker denoting their original places in line. 
	One person can bribe at most two others. 
	For example, if 'n = 8' and Person5  bribes Person4, the queue will look like this: 1, 2, 3, 5, 4, 6, 7, 8.
	
	Fascinated by this chaotic queue, 
	you decide you must know the minimum number of bribes that took place to get the queue into its current state!

Function Description
	Complete the function minimumBribes in the editor below. 
	It must print an integer representing the minimum number of bribes necessary, 
	or Too chaotic if the line configuration is not possible.
	minimumBribes has the following parameter(s):
		q: an array of integers
		
Input Format
	The first line contains an integer 't', the number of test cases.
	Each of the next 't' pairs of lines are as follows:
	- The first line contains an integer 't', the number of people in the queue
	- The second line has 'n' space-separated integers describing the final state of the queue.

Output Format
	Print an integer denoting the minimum number of bribes needed to get the queue into its final state. 
	Print Too chaotic if the state is invalid, i.e. it requires a person to have bribed more than 2 people.
	
Link: https://www.hackerrank.com/challenges/new-year-chaos/problem



About the Code
	Idea of lower-bound
    	Doesn't matter how many bribe person at q[upperBound] take, 
    	people who gave bribe to q[upperBound] cannot go in front of q[upperBound] - 2.

        Example:
        1 2 3 4 5 6 7 8 9 10
        If Person4 get bribes from person5 ~ person10
        1 2 3 5 6 7 8 9 10 4
        Now, Person5 is the first one of the people who gave the bribe.
        Since Person5 can give one more bribe, 
        Person5's final position can be
        1 2 5 3 6 7 8 9 10 4
        As shown in the above example, 
        people who can give bribe to q[upperBound] must be in the range of q[upperBound]-2