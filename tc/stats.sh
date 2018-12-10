#dlfile="tc.dl"

#echo "Compilation of $dlfile:"
#/usr/bin/time -f "TIME:[%E] MEM:[%M]" timeout 15m souffle $dlfile -F facts -w -o output --output-dir=/tmp/tmp.blah
#echo "Actual Running of $dlfile:"
#/usr/bin/time -f "TIME:[%E] MEM:[%M]" timeout 15m ./output > /dev/null

dlfile="tc.dl"
SOUFFLE="/home/rdow6615/souffle/src/souffle"
#############################
echo "Compiling $dlfile:"
/usr/bin/time \
    -f "TIME:[%E] MEM:[%M]" \
    timeout 15m \
    CPPFLAGS="-pg" \
    $SOUFFLE $dlfile \
    -F facts \
    -w  \
    -o output \
    --output-dir=/tmp/tmp.blah \
##############################
echo "Running $dlfile:"
/usr/bin/time \
  -f "TIME:[%E] MEM:[%M]" \
  timeout 15m \
  ./output > /dev/null
