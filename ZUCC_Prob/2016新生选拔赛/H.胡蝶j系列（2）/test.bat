@echo off
cd /d %~dp0

if exist test.cpp (
 
  test < data.in > test.out
  python win2nix.py test.out test.out


  if exist spj.cpp (
    g++ -std=gnu++11 -O2 spj.cpp -o spj.exe
    spj data.in data.out data.out
    spj data.in data.out test.out
    del spj.exe
  ) else (
    fc data.out test.out
  )
) else (
  echo test.cpp not found
)

pause
