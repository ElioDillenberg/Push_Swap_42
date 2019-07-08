ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;
./push_swap $ARG | wc -l;
./push_swap $ARG | ./checker $ARG;

ARG="4 2 5";
./push_swap $ARG | wc -l;
./push_swap $ARG | ./checker $ARG;
