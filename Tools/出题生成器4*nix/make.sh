#@echo off
#cd /d %~dp0

if [ -e "make.cpp" ]; then
    g++ -std=gnu++11 -O2 make.cpp -o make
    ./make > data.in
    rm make
fi

g++ -std=gnu++11 -O2 std.cpp -o std
python3 win2nix.py data.in data.in
./std < data.in > data.out
python3 win2nix.py data.out data.out

rm std

sleep
