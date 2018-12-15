## SOME OF THE OPTIONS / CONSTANTS

programs=(pointsto tc topological_ordering)
SOUFFLE="/home/rdow6615/souffle/src/souffle"
BENCHMARKS="/home/rdow6615/benchmarks/benchmarks"
temp_file="really-unique-filename"

simple() {
   for program in "${programs[@]}"
   do
    # print test_name

    for ((n=0;n<10;n++))
    do
      printf "$program,"
      # generate some facts
      $BENCHMARKS/$program/gen_facts.sh > /dev/null
      # now do the first step, how do I make sure there's no newline though with this output
      # YEP IT'S ALL GOOD just go for it
      { /usr/bin/time -f "%e,%U,%S,%M" \
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
      -f  ",%e,%U,%S,%M" \
      $SOUFFLE-compile output.cpp; } &>> $temp_file
      perl -pi -e 'chomp if eof' $temp_file
      
      ## this is for the actual execution
      { /usr/bin/time \
      -f ",%e,%U,%S,%M" \
      timeout 15m \
      ./output > /dev/null; } &>> $temp_file

      cat $temp_file
   done
  done
# cleanup
  rm $temp_file
   
}

pretty() {
  NOCOLOUR='\033[0m'
  RED='\033[0;31m'
  YELLOW='\033[1;33m'
  PURPLE='\033[0;35m'

  # call the other function and use its output in temp2
  simple > temp2

  OLDIFS=$IFS
  IFS=","

  count=0
  while read name d2creal d2cuser d2csys d2cmem c2oreal c2ouser c2osys c2omem runreal runuser runsys runmem
    do
      if [ $count -eq 0 ] 
      then
        echo -e "${RED}================ $name ================"
      fi
      ### now just write the normal stuff
      echo -e "${YELLOW}******** Run $count **********"
      echo -e "${PURPLE}\tDatalog -> C++"
      echo -e "${NOCOLOUR}\t\tReal:\t$d2creal s\n\t\tUser:\t$d2cuser s\n\t\tSystem:\t$d2csys s\n\t\tMemory usage:\t$d2cmem kB"
      echo -e "${PURPLE}\tC++ -> .o"
      echo -e "${NOCOLOUR}\t\tReal:\t$c2oreal s\n\t\tUser:\t$c2ouser s\n\t\tSystem:\t$c2osys s\n\t\tMemory usage:\t$c2omem kB"
      echo -e "${PURPLE}\tRunning..."
      echo -e "${NOCOLOUR}\t\tReal:\t$runreal s\n\t\tUser:\t$runuser s\n\t\tSystem:\t$runsys s\n\t\tMemory usage:\t$runmem kB"

      ((count+=1))
      if [ $count -eq 10 ] 
      then
        count=0
      fi

    done < temp2

  IFS=$OLDIFS 

}


## echo the column names
#echo "test_name,datalog->.cpp real (s),datalog->cpp user (s),datalog->cpp sys (s),.cpp->.o real (s),.cpp -> .o user (s),.cpp -> .o sys (s),runtime real (s),runtime user (s),runtime sys (s),memory consumption (kB)";

## check the flag

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
