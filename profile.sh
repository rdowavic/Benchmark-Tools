##### The first argument can be what .dl file do you want to profile?
##### Then I'll just give you a flat profile. It is really simple my man.
SOUFFLE="/home/rdow6615/souffle/src/souffle"
program=$1
#################


pretty() {
  simple > temp1
  while read percentage numcalls name 
    do
      echo -e "\e[1;33m$percentage% of $1 runtime\
      ==============================================================================================\e[0m\n\
      Function:\t ${name:0:100}...\n\
      Number of Calls:\t $numcalls\n"
    done < temp1
}


simple() {
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
        echo -e "$percentage\t$calls\t$name"
      fi
    done < temp

  rm temp
}

## deal with flags

options=$(getopt -o p --long pretty -- "$@")
eval set -- "$options"

while true ; do
  case "$1" in
    --pretty|-p)
        pretty; exit;
        ;;
     --)
        shift
        break
        ;;
  esac
  shift
done

simple
