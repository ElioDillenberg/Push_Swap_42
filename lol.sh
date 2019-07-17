ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;
./push_swap $ARG | ./checker -i $ARG;
