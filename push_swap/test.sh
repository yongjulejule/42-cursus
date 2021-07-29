./rand $1 | cat > log; cat log; echo "\n";  cat log | xargs ./push_swap > ops; cat ops; cat ops | wc -l
rm log ops
