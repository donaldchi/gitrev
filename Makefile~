sample: sample.c++
	g++ -Wall -std=c++11 -o $@ $^

PROJECT_REV:=$(shell ./utils/rev)
run: sample
	mkdir -p $(PROJECT_REV)
	/usr/bin/env PROJECT_REV=$(PROJECT_REV) ./sample

clean:
	rm -f sample

export:
	cp -r Makefile sample.c++ utils ../../../../smartguys/wakita/work/gitrev
