all: oop_exercise_03

oop_exercise_03: main.o
	g++ main.o  -o oop_exercise_03

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o oop_exercise_03