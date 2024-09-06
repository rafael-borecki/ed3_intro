TARGET=main
LD=gcc
SRC=main.c speciesRoutines.c funcoesFornecidas.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(LD) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
