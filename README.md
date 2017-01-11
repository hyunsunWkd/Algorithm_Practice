# Algorithm_Practice

<h2> Practice1 - Maximal sum of array (c++) </h2>

<h3> Question is.. </h3>

Given integer array, get and integer denoting the maximum possible integer sum of the array without reordering them.
The following conditions are satisfied:
-The collective sum of their numbers is maximal.
-It must go through the array in order and cannot skip more than one number in a row. Fore example, if ratings = {-1, -3, -2}, it must include either the second number or the first and third numbers to get a maximal rating sum of -3.

<h3> My algorithm is.. </h3>

-Positive Number => always plus

-Negative Number - skip possible - How many successive negative number is - 1 => skip
                                                                          - even number - numbering[i] < numbering[i+1] => skip(i)
                                                                                        - numbering[i] > numbering[i+1] => skip(i+1)
                                                                          - odd number - second number is min among three => skip(i+1)
                                                                                       - not => skip(i), skip(i+2)
                 - skip impossible => plus

<p>1. Positive Number or Negative Number?</p>
<p>2. If it is Negative Number, Is it possible to skip?</p>
<p>2-1. If it is possible, How many successive Negative Number?</p>
<p>2-1-1. If successive negative number is 1, skip the number for getting a maximal sum.</p>
<p>2-1-2. If successive negative number is even number => numbering[i] < numbering[i+1] => skip(i)</p>
<p>                                                => numbering[i] > numbering[i+1] => skip(i+1)</p>
<p>2-1-3. If successive negative number is odd number => second number is min among three => skip(i+1)</p>
<p>                                               => second number is not min among three => skip(i), skip(i+2)</p>
<p>2-1. If it is not possible</p>


<h2> Practice2 - Delete nodes greater than x (c++) </h2>

<h3> Question is.. </h3>

The Function should remove all nodes from the list having data values greater than x, and then return the head of the modified linked list.

<h3> My algorithm is.. </h3>

<p> 1. Make 'before' and 'deleteNode' pointer of linked list </p>
<p> 2. If deleteNode is head of the linked list </p>
<p> 3. If deleteNode is between two nodes </p>
<p> 4. If deleteNode is tail of the linked list </p>


<h2> Practice3 - Minimum Swaps (c++) </h2>

<h3> Question is.. </h3>

We want to rearrange the random items in a single row by decreasing popularity rating such that the rating for the ith item is always greater than the popularity rating of the (i+1)th item. The Function must return an integer denoting the minimum number of swap operations.

<h3> My algorithm is.. </h3>

Selection sort algorithm's the number of swap operation is the minimum. So I rearranged the  array by using selection sort.
