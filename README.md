# Algorithm_Practice

<h2> Practice1 - c++ </h2>

<h3> Question is.. </h3>

Given integer array, get and integer denoting the maximum possible integer sum of the array without reordering them.
The following conditions are satisfied:
-The collective sum of their numbers is maximal.
-It must go through the array in order and cannot skip more than one number in a row. Fore example, if ratings = {-1, -3, -2}, it must include either the second number or the first and third numbers to get a maximal rating sum of -3.

<h3> My algorithm is.. </h3>

-Positive Number => always plus

-Negative Number - skip possible - How many successive negative number is - 1 => skip
                                                                          - even number - numbering[i] < numbering[i+1] => skip(i)
                                                                                        - numbering[i] < numbering[i+1] => skip(i+1)
                                                                          - odd number - second number is min among three => skip(i+1)
                                                                                       - not => skip(i), skip(i+2)
                 - skip impossible => plus
