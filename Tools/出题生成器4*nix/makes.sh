#@echo off
#cd /d %~dp0

if [ -e "make.cpp" ]; then
    g++ -std=gnu++11 -O2 make.cpp -o make
fi


g++ -std=gnu++11 -O2 std.cpp -o std

for((cnt=1;cnt<=$1;cnt++))
do
	./make > data$cnt.in
	python3 win2nix.py data$cnt.in data$cnt.in
	./std < data$cnt.in > data$cnt.out
	python3 win2nix.py data$cnt.out data$cnt.out
done

rm make
rm std
sleep
