# Before Final

- Case A : "Jojo and Trains"
- Case B : "Mid-Year Gifts"
- Case C : "Domain Filtering"
- Case D : "Find the Word"
- Case E : "Company Dinner"
- Case H : "Bubble Shuffle"

# Notes

- Case A :
Use struct as data structure, sort the struct after id and time input, use another struct as placeholder for source and destiny input then pass it to struct with specified id (get id with binary search).   

- Case B : 
Make a struct of string and create a string variable as a placeholder, take the number input as index, use strcpy to copy placeholder to struct based on index.

- Case C : 
Sort array of string, use binary search to get the first and last occurence of string, get the result by: [last index]-[first index]+1.

- Case D : 
Find the matched first letter in puzzle, check each letter at horizontal and vertical side, if numbers of the letter matched the length of string print "yes".

- Case E : 
Same as case C, find the first and last index, get the result by: [last index]-[first index]+1.

- Case H :
create 3 array : array A (ori), array B (permute), and list_index. compare each number from array A with array B, if the numbers are equal put the array A index in list_index, sort array list_index using bubble sort and count every swap in bubble sort logic. 