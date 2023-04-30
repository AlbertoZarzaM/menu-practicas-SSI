CXX		  := g++ 
CXX_FLAGS :=   -std=c++17 -ggdb 

all: CHACHA

CHACHA: 
	$(CXX)  -o ./menu ./*.cpp 

clean:

	rm -f ./menu