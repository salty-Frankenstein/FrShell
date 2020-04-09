shell:main.o
	g++ --std=c++11 main.o -o shell
main.o:main.cpp
	g++ --std=c++11 -c main.cpp -o main.o
shell.o:shell.cpp shell.h
	g++ --std=c++11 -c shell.cpp shell.h -o shell.o
cmdparser.o:cmdparser.cpp cmdparser.h
	g++ --std=c++11 -c cmdparser.cpp cmdparser.h -o cmdparser.o
clean:
	rm *.o
open:
	vim main.cpp shell.cpp shell.h cmdparser.cpp cmdparser.h


