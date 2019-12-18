# push_swap

Push_Swap aims to introduce students to sorting algorithms. It requires you to sort data on a stack with the use of a second stack and a limited set of instructions. 

Set of available instructions:

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

All elements given by the user are first placed on the A stack. Your goal is to sort the A stack (lowest value on top) using the lowest amount of instructions above.

More details can be found within the official subject PDF in the subject folder.
