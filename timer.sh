programs=(pointsto tc topological_ordering)
SOUFFLE="/home/rdow6615/souffle/src/souffle"
BENCHMARKS="/home/rdow6615/benchmarks/benchmarks"
temp_file="really-unique-filename"

## echo the column names
echo "test_name,datalog->.cpp real (s),datalog->cpp user (s),datalog->cpp sys (s),.cpp->.o real (s),.cpp -> .o user (s),.cpp -> .o sys (s),runtime real (s),runtime user (s),runtime sys (s),memory consumption (kB)";

for program in "${programs[@]}"
do
  # print test_name

  for ((n=0;n<10;n++))
  do
    printf "$program, "
    # generate some facts
    $BENCHMARKS/$program/gen_facts.sh > /dev/null
    # now do the first step, how do I make sure there's no newline though with this output
    # YEP IT'S ALL GOOD just go for it
    { /usr/bin/time -f "%E,%U,%S," \
    timeout 15m \
    $SOUFFLE "$BENCHMARKS/$program/$program.dl" \
    -F facts \
    -w \
    --output-dir=/tmp/tmp.blah \
    -g output.cpp; } &> $temp_file
    ## get rid of the bloody trailing newline that time causes
    perl -pi -e 'chomp if eof' $temp_file

    ## this is for cpp->.o
    { /usr/bin/time \
    -f  "%E,%U,%S," \
    $SOUFFLE-compile output.cpp; } &>> $temp_file
    perl -pi -e 'chomp if eof' $temp_file
    
    ## this is for the actual execution
    { /usr/bin/time \
    -f "%E,%U,%S,%M" \
    timeout 15m \
    ./output > /dev/null; } &>> $temp_file

    cat $temp_file
 done
done
