
rm wc_output/med_result.txt wc_output/wc_result.txt

g++ -o hbs_word_count.out hbs_word_count.cc
g++ -o hbs_median_count.out hbs_median_count.cc

./hbs_word_count.out
./hbs_median_count.out

