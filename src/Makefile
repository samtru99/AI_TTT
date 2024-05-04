CXX = g++

CFLAGS = -std=c++17 -g

main: main.o Generate_Q_Table.o
	$(CXX) $(CFLAGS) -o main main.o Generate_Q_Table.o

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

Generate_Q_Table.o: Generate_Q_Table.cpp
	$(CXX) $(CFLAGS) -c Generate_Q_Table.cpp

clean:
	rm -f main main.o Generate_Q_Table.o