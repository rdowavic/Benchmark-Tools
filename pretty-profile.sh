## use profile to print the pretty version of the profiler. We put the name of the program
## and also like column stuff. Check out that bash tutorial
touch temp1
./profile.sh $1 > temp1

while read percentage numcalls name 
  do
    echo -e "\e[1;33m$percentage% of $1 runtime\
    ==============================================================================================\e[0m\n\
    Function:\t ${name:0:100}...\n\
    Number of Calls:\t $numcalls\n"
  done < temp1
