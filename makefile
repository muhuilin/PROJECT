.PHONY : all run clean
all: 
	g++ -DTEST_RUN src/*.cc ./main.cpp -I ./include -o ./bin/test
run: 
	./bin/test
clean :
	rm -rf ./bin/test *.o
