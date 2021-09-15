CC=gcc
INCLUDE=-I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include/ -Iinclude/
CFLAGS=-Wall -Wextra
LDFLAGS=-ldbus-1 -ldbus-glib-1 -lglib-2.0 -lgio-2.0 -lgobject-2.0 -lgthread-2.0
EXEC=test

all: $(EXEC)


test: main.o proxSensors.o buttons.o otherSensors.o motors.o map.o computePath.o detection.o movement.o orientation.o advanced.o pathExecution.o exploration.o
	$(CC) -g $^ -o $(EXEC) $(INCLUDE) $(CFLAGS) $(LDFLAGS)


exploration.o: level5/exploration.c
	$(CC) -c level5/exploration.c -o exploration.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)



pathExecution.o: level4/pathExecution.c
	$(CC) -c level4/pathExecution.c -o pathExecution.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)



advanced.o: level3/advanced.c
	$(CC) -c level3/advanced.c -o advanced.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)

orientation.o: level3/orientation.c
	$(CC) -c level3/orientation.c -o orientation.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)




movement.o: level2/movement.c
	$(CC) -c level2/movement.c -o movement.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)




detection.o: level1/detection.c
	$(CC) -c level1/detection.c -o detection.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)

computePath.o: level1/computePath.c
	$(CC) -c level1/computePath.c -o computePath.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)




map.o: level0/map.c
	$(CC) -c level0/map.c -o map.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)

motors.o: level0/motors.c
	$(CC) -c level0/motors.c -o motors.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)

otherSensors.o: level0/otherSensors.c
	$(CC) -c level0/otherSensors.c -o otherSensors.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)

proxSensors.o: level0/proxSensors.c
	$(CC) -c level0/proxSensors.c -o proxSensors.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)

buttons.o: level0/buttons.c
	$(CC) -c level0/buttons.c -o buttons.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)




main.o: main.c
	$(CC) -c main.c -o main.o $(INCLUDE) $(CFLAGS) $(LDFLAGS)




clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
