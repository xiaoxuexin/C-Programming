proj5.exe: SimulationClass.o random.o EventClass.o CustomerClass.o constant.h main.o
	g++ SimulationClass.o random.o EventClass.o CustomerClass.o constant.h main.o -o proj5.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

SimulationClass.o: SimulationClass.cpp
	g++ -c SimulationClass.cpp -o SimulationClass.o

random.o: random.cpp
	g++ -c random.cpp -o random.o

EventClass.o: EventClass.cpp
	g++ -c EventClass.cpp -o EventClass.o

CustomerClass.o: CustomerClass.cpp
	g++ -c CustomerClass.cpp -o CustomerClass.o

clean:
	rm -f proj5.exe main.o SimulationClass.o random.o EventClass.o CustomerClass.o
	echo Clean done

