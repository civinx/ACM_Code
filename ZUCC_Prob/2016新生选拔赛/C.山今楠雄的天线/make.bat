@echo off
cd /d %~dp0

if exist make.cpp (
    
    make > data.in
    
)


python win2nix.py data.in data.in
std < data.in > data.out
python win2nix.py data.out data.out

pause