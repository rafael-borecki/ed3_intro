TARGET=main
FUNC=funcoesFornecidas.c
SPEC=speciesRoutines.c
LD=gcc
OBJ=main.c
all: main.c
	$(LD) -o $(TARGET) $(OBJ) $(FUNC) $(SPEC)
run: $(TARGET)
	./$(TARGET)
