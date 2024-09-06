TARGET=main
FUNC=funcoesFornecidas.c
SPEC=speciesRoutines.c
LD=gcc
OBJ=main.c
all: main.c
	$(LD) $(OBJ) $(FUNC) $(SPEC) -o $(TARGET) 
run: $(TARGET)
	./$(TARGET)
