CC = gcc
CFLAGS = -g -Wall

exec = Exec/$(code)

dir-code = Source/$(code)

source-code = Source/$(code)

h-object = Objects/$(h).o

code-object = Objects/$(code).o

dir-h = Source/Bibliotecas/$(h)

blib: $(exec)

$(exec): $(h-object) $(code-object)
	@echo 'Compilando $(exec)...'
	$(CC) -o $(exec) $(h-object) $(code-object) $(CFLAGS)
	@echo -e 'Concluído\nExecutando $(code)...'
	./$(exec)

$(code-object): $(dir-code).c $(dir-h).h
	@echo 'Compilando $(code-object)'
	$(CC) -o $(code-object) $(dir-code).c $(CFLAGS) -c
	@echo -e 'Concluído\n'

$(h-object): $(dir-h).c $(dir-h).h
	@echo 'Compilando $(h-object)'
	$(CC) -o $(h-object) $(dir-h).c $(CFLAGS) -c
	@echo -e 'Concluído\n'

c: $(dir-code).c
	@echo 'Compilando $(dir-code)...'
	$(CC) -o $(exec) $(dir-code).c $(CFLAGS)
	@echo -e 'Concluído\nExecutando $(code)...'
	./$(exec)

clean-b:
	rm -f *.o *~ $(exec)
	rm -f *.o *~ $(code-object)
	rm -f *.o *~ $(h-object)

clean:
	rm -f *.o *~ $(exec)
