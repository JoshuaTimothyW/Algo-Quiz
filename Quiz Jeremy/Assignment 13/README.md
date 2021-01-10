# Assignment 13

Case A : "Plant Sorting" 
Case B : "Max Number"
Case C : "Searching"
Case D : "Binary Search"
Case E : "Magic Potion"
Case F : "Prime Triangle"

# Notes

- Case A : 
Read file and sort (quick or merge sort).

- Case B : 
Sort array, remove the number from array using binary search, take the last element as max number.

- Case C : 
Read file and search (binary).

- Case D : 
This case a little bit tricky, so the first step is to use binary search, take the middle value, calculate it with the formula. The important thing to notice is the data type, the formula can result decimal so you have to use double. then if the result is greather equal than target. set minimum value from middle, then return minimum value after a loop finished.

- Case E : 
Just use 3 nested loop to get exact sum and it works (Didn't find good solution with binary search).

- Case F : 
Generate 100 prime numbers, exact total numbers print in triangle shape is 5050
Each prime number % 10 in array.