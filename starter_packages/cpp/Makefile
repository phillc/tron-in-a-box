# The Makefile
#
# If you're using Windows and you don't know what this file is,
# don't worry about it. Just use Visual C++ Express Edition or
# Dev-C++ to work on your code. Mac users can use Xcode.

MyTronBot: MyTronBot.o Map.o Point.o Direction.o
	g++ -O2 -o MyTronBot MyTronBot.o Map.o Point.o Direction.o

MyTronBot.o: MyTronBot.cc
	g++ -O2 -c -o MyTronBot.o MyTronBot.cc

Map.o: Map.cc
	g++ -O2 -c -o Map.o Map.cc
	
Point.o: Point.cc
	g++ -O2 -c -o Point.o Point.cc

Direction.o: Direction.cc
	g++ -O2 -c -o Direction.o Direction.cc
	
clean:
	rm Map.o Point.o Direction.o MyTronBot.o MyTronBot