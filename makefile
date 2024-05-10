files := src/main.cpp

build/techtactoe : build/main.o
	g++ -o $@ $^

build/main.o : src/main.cpp
	g++ -c $^ -o $@

clean:
	rm -f build/main.o