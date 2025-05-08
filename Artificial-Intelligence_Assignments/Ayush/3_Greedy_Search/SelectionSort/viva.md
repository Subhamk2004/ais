Summary
Selection Sort is an in-place comparison sorting algorithm that maintains two subarrays—a sorted portion and an unsorted portion—and repeatedly selects the minimum element from the unsorted portion and swaps it into its correct position at the boundary. 
It divides the array into a sorted left part (initially empty) and an unsorted right part (initially the whole list). 
On each pass, it scans the unsorted subarray to find the minimum element, then swaps it with the first unsorted element, thereby growing the sorted subarray by one element 
Selection So.rt runs in 
𝑂(𝑛^2)
time for best, average, and worst cases and uses only 
O(1) auxiliary space .




Selection Sort
Explanation of Working Concept
At each iteration, Selection Sort treats the first i elements of the array as sorted and the remaining n-i elements as unsorted. It finds the smallest element in the unsorted subarray by scanning all unsorted elements, then swaps that minimum with the element at index i, effectively extending the sorted region by one.
Step-by-Step Example
Consider the array [64, 25, 12, 22, 11].
Pass 1 (i = 0): Minimum among [64, 25, 12, 22, 11] is 11. Swap with element at index 0 ⇒ [11, 25, 12, 22, 64]
Pass 2 (i = 1): Minimum among [25, 12, 22, 64] is 12. Swap with element at index 1 ⇒ [11, 12, 25, 22, 64]
Pass 3 (i = 2): Minimum among [25, 22, 64] is 22. Swap with element at index 2 ⇒ [11, 12, 22, 25, 64]
Pass 4 (i = 3): Minimum among [25, 64] is 25, already at index 3, so no swap needed ⇒ [11, 12, 22, 25, 64]
After n-1 passes, the array is fully sorted.





Selection Sort
Explanation of Working Concept

At each iteration, Selection Sort treats the first i elements of the array as sorted and the remaining n-i elements as unsorted. It finds the smallest element in the unsorted subarray by scanning all unsorted elements, then swaps that minimum with the element at index i, effectively extending the sorted region by one.
Step-by-Step Example
Consider the array [64, 25, 12, 22, 11].
Pass 1 (i = 0): Minimum among [64, 25, 12, 22, 11] is 11. Swap with element at index 0 ⇒ [11, 25, 12, 22, 64]
Pass 2 (i = 1): Minimum among [25, 12, 22, 64] is 12. Swap with element at index 1 ⇒ [11, 12, 25, 22, 64]
Pass 3 (i = 2): Minimum among [25, 22, 64] is 22. Swap with element at index 2 ⇒ [11, 12, 22, 25, 64]
Pass 4 (i = 3): Minimum among [25, 64] is 25, already at index 3, so no swap needed ⇒ [11, 12, 22, 25, 64]
After n-1 passes, the array is fully sorted.




Viva Questions and Answers


1. What is the core idea behind Selection Sort?
The core idea behind Selection Sort is to repeatedly find the minimum element from the unsorted portion of the array and put it at the beginning of the unsorted portion. This effectively builds up a sorted subarray from left to right. The algorithm divides the input into two parts: a sorted subarray that grows from left to right and an unsorted subarray that corresponds to the remaining elements.


2. How does Selection Sort differ from Bubble Sort and Insertion Sort?
Selection Sort vs. Bubble Sort:

Selection Sort makes exactly n-1 swaps (one per iteration), while Bubble Sort can make O(n²) swaps in worst case.
Selection Sort always selects the minimum element and places it at the correct position.
Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they're in the wrong order.

Selection Sort vs. Insertion Sort:

Selection Sort always processes the array from left to right in a fixed pattern.
Insertion Sort builds the sorted array one element at a time by picking elements from the unsorted part and inserting them at the correct position in the sorted part.
Insertion Sort performs well on nearly sorted arrays (O(n) in best case), while Selection Sort always takes O(n²) regardless of input.


3. Write the pseudocode for Selection Sort and explain each step.
procedure selectionSort(array A)
    n = length(A)
    for i = 0 to n-2 do
        minIndex = i
        for j = i+1 to n-1 do
            if A[j] < A[minIndex] then
                minIndex = j
            end if
        end for
        if minIndex != i then
            swap A[i] and A[minIndex]
        end if
    end for
end procedure
Explanation:

Start with the first element (index 0) as the assumed minimum.
Search the rest of the array to find the actual minimum.
Swap the found minimum with the first element if necessary.
Move to the next index and repeat the process.
Continue until the entire array is sorted.



4. Why is Selection Sort not considered a stable sorting algorithm?
Selection Sort is not stable because it may change the relative order of equal elements. When swapping elements, it might move an equal element past several others, disrupting their original sequence.
For example, with array [4, 2, 3, 4*, 1] (where 4* is used to distinguish the second 4), after sorting, we might get [1, 2, 3, 4*, 4] instead of [1, 2, 3, 4, 4*], which doesn't preserve the original relative order of the equal elements.


5. What are the time complexities of Selection Sort in best, average, and worst cases?

Best case: O(n²) - Even if the array is already sorted, the algorithm still needs to scan the entire array.
Average case: O(n²) - The algorithm always performs the same number of comparisons.
Worst case: O(n²) - Same as best and average cases.


6. Explain why Selection Sort's best-case time complexity remains O(n²).
Selection Sort's best-case time complexity remains O(n²) because regardless of the input array's initial order (even if it's already sorted), the algorithm still needs to scan the entire unsorted portion of the array to find the minimum element in each iteration. It cannot take advantage of any existing order in the array, unlike algorithms like Insertion Sort or Bubble Sort that can achieve O(n) time complexity on sorted arrays.


7. What is the space complexity of Selection Sort, and why?
The space complexity of Selection Sort is O(1) or constant space. This is because it performs the sorting in-place, using only a constant amount of extra space regardless of the input size. The algorithm only needs a few variables (like indices and a temporary variable for swapping) that don't depend on the size of the input array.


8. Can Selection Sort be efficient on certain types of hardware or datasets?
Selection Sort can be efficient in situations where:

Memory writing is a costly operation, as it minimizes the number of swaps (exactly n-1 swaps).
The input array is small.
The system has simple hardware with limited memory.
Checking is cheaper than swapping (for example, when array elements are large records with multiple fields but comparisons are based on a small key field).


9. How many swaps does Selection Sort perform in the worst case?
Selection Sort performs exactly n-1 swaps in all cases (including worst case), where n is the size of the array. This is because in each iteration, it makes at most one swap (when the minimum element is not already at the correct position).


10. Describe a scenario where you might choose Selection Sort over Quick Sort or Merge Sort.
Selection Sort might be preferred over Quick Sort or Merge Sort in the following scenarios:

When memory usage is a concern (Selection Sort is in-place with O(1) space complexity).
When the array size is very small (the overhead of recursive algorithms like Quick Sort or Merge Sort might not be worth it).
When the number of writes to memory needs to be minimized (Selection Sort performs exactly n-1 swaps).
In embedded systems with limited resources where algorithm simplicity is more important than performance for large datasets.
When dealing with external storage where read operations are significantly cheaper than write operations.