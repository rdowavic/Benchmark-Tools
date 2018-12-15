# get the stuff produced
./timer.sh > temp2

NOCOLOUR='\033[0m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
PURPLE='\033[0;35m'

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
