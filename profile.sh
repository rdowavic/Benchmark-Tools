##### The first argument can be what .dl file do you want to profile?
##### Then I'll just give you a flat profile. It is really simple my man.
SOUFFLE="/home/rdow6615/souffle/src/souffle"
program=$1
##################
# 1. compile the .dl file
CPPFLAGS="-pg" $SOUFFLE $program -F facts -w -o output --output-dir=/tmp/tmp.blah
# 2. run it and suppress the output
echo "Running the program to generate runtime statistics..."
./output > /dev/null
# 3. Run gprof
echo ""
gprof output gmon.out --flat-profile --brief


