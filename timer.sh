echo "******************************************************************************"
echo "************* THIS MEASURES THE RUNTIME, MEMORY CONSUMPTION OF ***************"
echo "************** A SUITE OF REPRESENTATIVE PROGRAMS FOR SOUFFLE ****************"
echo "******************************************************************************"

programs=(pointsto tc topological_ordering)
SOUFFLE="/home/rdow6615/souffle/src/souffle"
BENCHMARKS="/home/rdow6615/benchmarks/benchmarks"
echo ""
echo "Programs: ${programs[*]}"
echo ""

for program in "${programs[@]}"
do
  # make sure we generate some new facts 
  # using that handy script
  $BENCHMARKS/$program/gen_facts.sh > /dev/null
  echo "********* $program *********"
  echo "# Datalog -> C++:"
    /usr/bin/time \
    -f "User: %Us\nSys: %Ss\nReal: %Es\nMemory: %M kB\n" \
    timeout 15m \
    $SOUFFLE "$BENCHMARKS/$program/$program.dl" \
    -F facts \
    -w \
    --output-dir=/tmp/tmp.blah \
    -g output.cpp

  echo "# C++ -> Binary Exec:"
    /usr/bin/time \
    -f "User: %Us\nSys: %Ss\nReal: %Es\n" \
    $SOUFFLE-compile output.cpp
  echo "# Running...:"
    /usr/bin/time \
    -f "User: %Us\nSys: %Ss\nReal: %Es\nMemory: %M kB\n" \
    timeout 15m \
    ./output > /dev/null
done
