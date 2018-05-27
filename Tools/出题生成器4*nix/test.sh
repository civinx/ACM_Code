# @echo off
# cd /d %~dp0

if [ -e "test.cpp" ]; then
  g++ -std=gnu++11 -O2 test.cpp -o test
  ./test < data.in > test.out
  python3 win2nix.py test.out test.out
  rm test

  if [ -e  spj.cpp ]; then
    g++ -std=gnu++11 -O2 spj.cpp -o spj
    ./spj data.in data.out data.out
    ./spj data.in data.out test.out
    rm spj
  else
    diff data.out test.out
  fi
else
  echo test.cpp not found
fi

sleep
