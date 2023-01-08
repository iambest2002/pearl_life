 gcc -fPIC -shared arrsort.cpp  -o libarrsort.so  & sudo cp libarrsort.so  /usr/lib

g++ main.cpp  -std=c++11  -g    -larrsort -o a 

./a
