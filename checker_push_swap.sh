ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;
./push_swap $ARG | wc -l;
./push_swap $ARG | ./checker $ARG;

ARG="2 4 8";
./push_swap $ARG;
./push_swap $ARG | wc -l;
./push_swap $ARG | ./checker $ARG;
