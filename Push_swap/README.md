Optimized algorithmic project in C, I was able to perfect my use of chained lists thanks to this challenge where optimization was essential. In the end, my skills in memory management, rigor and analysis could only improve.

Sorting is performed with these commands :

sa (swap a): Swaps the first 2 elements at the top of the a stack.
Does nothing if there is only one or none.

sb (swap b ): Swaps the first 2 elements at the top of stack b.
Does nothing if there is only one or none.

ss : sa and sb at the same time.

pa (push a): Takes the first element at the top of b and puts it on a.
Does nothing if b is empty.

pb (push b): Takes the first element on top of a and sets it to b.
Does nothing if a is empty.

ra (rotate a): Shifts all elements in stack a upwards by one position.
The first element becomes the last.

rb (rotate b): Shifts all elements in stack b up one position.
The first element becomes the last.

rr: ra and rb at the same time.

rra (reverse rotate a): Shifts all stack elements down one position.
a stack. The last element becomes the first.

Launch the project with make, and: ./push_swap "list of nb".
