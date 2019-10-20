CC = gcc
CFLAGS = -g -Wall

ED = fila

ALL = clienteFila

all: $(ALL)

$(ED).o: $(ED).h $(ED).c

clienteFila: $(ED).o $(ALL).c

clean:
	rm -f *.o *~ $(ALL)