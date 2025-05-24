all: compile run


compile:
	g++ -std=c++11 -c -I ./include/ ./src/dugumGosterimi.cpp -o ./lib/dugumGosterimi.o
	g++ -std=c++11 -c -I ./include/ ./src/agacCizim.cpp -o ./lib/agacCizim.o
	g++ -std=c++11 -c -I ./include/ ./src/agacDeger.cpp -o ./lib/agacDeger.o
	g++ -std=c++11 -I ./include/ ./lib/agacDeger.o ./lib/agacCizim.o ./lib/dugumGosterimi.o ./src/main.cpp -o ./bin/main.exe

run:
	./bin/main.exe