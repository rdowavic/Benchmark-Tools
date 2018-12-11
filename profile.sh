##### The first argument can be what .dl file do you want to profile?
##### Then I'll just give you a flat profile. It is really simple my man.
SOUFFLE="/home/rdow6615/souffle/src/souffle"
program=$1
#################
# 0. GENERATE THE FACTS
$program/gen_facts.sh > /dev/null

# 1. compile the .dl file
CPPFLAGS="-pg" $SOUFFLE $program/$program.dl -F facts -w -o output --output-dir=/tmp/tmp.blah
# 2. run it and suppress the output
./output > /dev/null
# 3. Run gprof
gprof output gmon.out --flat-profile --brief > temp
# delete first rubbish lines
sed -i -e 1,5d temp

while read percentage cumulative self calls selfmscall totalmscall name      
  do
    int=`echo "$percentage/1" | bc`
    if [ $int -gt 1 ]
    then
      echo "$percentage, $calls, $name"
    fi
  done < temp




