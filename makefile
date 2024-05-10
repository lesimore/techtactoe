files := src/main.cpp

bin/techtactoe : bin/main.o
	g++ -o $@ $^

bin/main.o : src/main.cpp
	g++ -c $^ -o $@

clean:
	rm -f bin/main.o