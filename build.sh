git pull
rm CMakeCache.txt
cmake .
make -j16 2>&1 | grep error
