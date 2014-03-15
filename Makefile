gitrev: gitrev.c++
	g++ -Wall -std=c++11 -o $@ $^

clean:
	rm gitrev
