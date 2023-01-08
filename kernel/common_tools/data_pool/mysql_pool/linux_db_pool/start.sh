 g++ -fPIC -shared connect.cpp -std=c++11 -I/usr/include/mysql -L/usr/lib64/mysql  -o libsql.so  


#& sudo cp libsql.so  /usr/lib