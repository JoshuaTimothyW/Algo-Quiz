# Before Final

- Case A : "Jojo and Trains"
- Case B : "Mid-Year Gifts"
- Case C : "Domain Filtering"
- Case D : "Find the Word"
- Case E : "Company Dinner"
- Case F : "Party Beverages"
- Case G : "Divisor Sort"
- Case H : "Bubble Shuffle"
- Case L : "The Famous Gauss"

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

- Case F :
Give additional conditions in binary search, like so:
    - If middle array + number <= total and mid < n-1 then check if mid+1 array > total then return mid index else set start = mid+1
    - else set end = mid-1
If the result is same as number or -1 then do not compare with max value.

- Case G : 
A very simple way is to make an array of struct with 2 attributes: original number and sum of its divisor, then follow the instruction on how to sort the array.

- Case H :
Create 3 array : array A (ori), array B (permute), and list_index. compare each number from array A with array B, if the numbers are equal put the array A index in list_index, sort array list_index using bubble sort and count every swap in bubble sort logic. 

- Case L :
Use 2 binary search to find minimum and maximum value in array. If the first number in array is larger than maximum number in range or the last number in array is smaller than  minimum number in range return -1. Otherwise sum numbers from the instrution. 