CC = g++
CFLAGS = -Wall
BIN = ./bin
SRC = ./src

sc:
	@echo "Compiling sources..."
	-d $(BIN) || mkdir -p $(BIN)
	$(CC) $(SRC)/*.cpp -o $(BIN)/$@ $(CFLAGS)
	@echo "Done."

clean:
	@echo "Deleting binaries..."
	rm -r $(BIN)
	@echo "Done."