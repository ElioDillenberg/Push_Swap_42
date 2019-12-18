# Push_Swap (42 School Project)

Push_Swap aims to introduce students to sorting algorithms. It requires you to sort data on a stack with the use of a second stack and a limited set of instructions. 

Set of available instructions:
<pre>
PA: push the top element from the B stack on top of the A stack                                                               
PB: push the top element from the A sack on top of the B stack                                                                 
SA: swap the top two element from the A stack                                                                                 
SB: swap the top two element from the B stack                                                                                 
RA: the first element of the A stack is pushed to the bottom of the A stack                                                   
RB: the first element of the B stack is pushed to the bottom of the B stack                                                   
RR: RA and RB simultaneously                                                                                                   
RRA: the last element of the A stack is pushed to the top of the A stack                                                       
RRB: the last element of the B stack is pushed to the top of the B stack                                                       
RRR: RRA and RRB simultaneously    
</pre>

All elements given by the user are first placed on the A stack. Your goal is to sort the A stack (lowest value on top) using the lowest amount of instructions above.

The push_swap binary takes care of sorting the elements and prints on stdout the use instructions.
The checker binary reads on stdin the instructions and checks wether the elements are sorted.
More details can be found within the official subject PDF in the subject folder.

# How to run:
<pre>
git clone https://github.com/ElioDillenberg/Push_Swap_42.git push_swap
cd push_swap
make
./push_swap 5 1 4 3 2 (enter your data to be sorted set here)
./push_swap 5 1 4 3 2 | ./checker 5 1 4 3 2 (to use the checker)
</pre>

The push_swap binary takes care of sorting the elements and prints on stdout the use instructions.
The checker binary reads on stdin the instructions and checks wether the elements are sorted.

Enjoy!
