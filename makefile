CC=g++
EXE_FILE=coffee_run

all: $(EXE_FILE)

$(EXE_FILE): coffee.o menu.o order.o shop.o display.o prog.o
	$(CC) coffee.o menu.o order.o shop.o display.o prog.o -o $(EXE_FILE)

coffee.o: coffee.h coffee.cpp
	$(CC) -c coffee.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp

menu.o: menu.h menu.cpp
	$(CC) -c menu.cpp

order.o: order.h order.cpp
	$(CC) -c order.cpp

shop.o: shop.h shop.cpp
	$(CC) -c shop.cpp

display.o: display.h display.cpp
	$(CC) -c display.cpp

clean:
	rm -f *.o $(EXE_FILE)