debug: 
	g++ -c ./src/*.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o ./build/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./build/debug/main 
release:
	g++ -c ./src/*.cpp -std=c++14 -m64 -O3  -Wall -I include && g++ *.o -o ./build/release/main -s -lSDL2main -lSDL2 -lSDL2_image && ./build/release/main
clean: 
	rm -rf ./build/*.o
