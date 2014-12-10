07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Add and remove are both O(log n) because both bubbleUp and trickleDown are recursive and can be called a total of log n times.
2. All arrays are deleted when they are no longer needed.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
		10.1 - When 7 is added it is placed at the ack of the array. The array is grown first if it is neccessary.
		Then bubbleUp is called to place it in the correct spot. The same then happens to 3 when it is added.

		10.2 - The top of the tree is always removed. To remove 6, it would first need to be replaced with 55, the last element.
		Then the 6 value would be deleted from the tree and trickleDown would be called to put 55 until it is put into the correct,
		left most spot. This is done recursively. The same would happen for 8 except it would need to switch with 93 and then 93
		would be recursively placed in the correct spot.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
		10.4 - I believe that you could find the child by just using d * i + n, n being the number of the child that 
		you are looking at. You can find the parent by using (i - 1) / d.

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

		My advice is to make sure that your bubbleUp and trickleDown functions work properly since they are the most important
		functions in this entire program. Without them nothing would work right.