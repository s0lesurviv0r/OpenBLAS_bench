CC=gcc
CFLAGS=-I. -O3 -L/opt/OpenBLAS/lib -lopenblas
OBJ_BENCH=main.o
BIN_BENCH=matrix_bench

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
    
build: $(OBJ_BENCH)
	gcc -o $(BIN_BENCH) $^ $(CFLAGS)
	
bench: $(BIN_BENCH)
	./$(BIN_BENCH)

clean:
	rm -f *.o
	rm -f $(BIN_BENCH)
