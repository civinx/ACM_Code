#if [ -e "test.cpp" ]; then
#    g++ -std=gnu++11 -O2 test.cpp -o test
#else
#    echo test.cpp not found !!!
#fi
#
#if [ -e "std.cpp" ]; then
#g++ -std=gnu++11 -O2 std.cpp -o std
#else
#echo std.cpp not found !!!
#fi
#
#if [ -e "make.cpp" ]; then
#g++ -std=gnu++11 -O2 make.cpp -o make
#else
#echo make.cpp not found !!!
#fi

if [ ! -e "test" ]; then
    echo test not found
    exit 0
fi

if [ ! -e "std" ]; then
    echo std not found
    exit 0
fi

if [ ! -e "make" ]; then
    echo make not found
    exit 0
fi

while true; do
    ./make > data.in
    ./std < data.in > std.out
    ./test < data.in > test.out
    if diff std.out test.out; then
        echo AC
    else
        echo WA
        echo
        echo data:
        cat data.in

        echo answer:
        cat std.out
        echo

        echo output:
        cat test.out
        exit 0
    fi
done

