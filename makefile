# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I.
LDFLAGS = 

# Directorios
BASE_DIR = .
BUILD_DIR = build
BIN_DIR = bin

# Archivos fuente (encuentra todos los .c en toda la estructura)
SOURCES = $(wildcard $(BASE_DIR)/*.c) \
          $(wildcard $(BASE_DIR)/*/*.c)

# Archivos objeto
OBJECTS = $(SOURCES:$(BASE_DIR)/%.c=$(BUILD_DIR)/%.o)

# Nombre del ejecutable principal
TARGET = $(BIN_DIR)/programa

# Regla principal
all: $(TARGET)

# Crear el ejecutable
$(TARGET): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compilar archivos .c a .o
$(BUILD_DIR)/%.o: $(BASE_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar específicamente main y ejecutar
main: $(BUILD_DIR)/main.o $(BUILD_DIR)/nodo/nodo.o $(BUILD_DIR)/colas/colas.o
	mkdir -p $(BIN_DIR)
	$(CC) $^ -o $(BIN_DIR)/main
	@echo "=== Ejecutando main ==="
	./$(BIN_DIR)/main

# Compilar solo main sin ejecutar
main-build: $(BUILD_DIR)/main.o $(BUILD_DIR)/nodo/nodo.o $(BUILD_DIR)/colas/colas.o
	mkdir -p $(BIN_DIR)
	$(CC) $^ -o $(BIN_DIR)/main

# Limpiar
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Ejecutar el programa principal
run: $(TARGET)
	./$(TARGET)

# Ejecutar main
run-main: main
	@echo "Listo"

# Ver qué archivos se van a compilar
list:
	@echo "Archivos fuente encontrados:"
	@find . -name "*.c" -not -path "./build/*" | sort
	@echo ""
	@echo "Total: $(words $(SOURCES)) archivos"

# Compilar solo un módulo específico
pilas: $(BUILD_DIR)/pilas/pilas.o $(BUILD_DIR)/nodo/nodo.o
	$(CC) $^ -o $(BIN_DIR)/test_pilas

colas: $(BUILD_DIR)/colas/colas.o $(BUILD_DIR)/nodo/nodo.o
	$(CC) $^ -o $(BIN_DIR)/test_colas

listas: $(BUILD_DIR)/lista/listas.o $(BUILD_DIR)/nodo/nodo.o
	$(CC) $^ -o $(BIN_DIR)/test_listas

# Debug
debug: CFLAGS += -DDEBUG -g3
debug: clean all

.PHONY: all clean run list debug main main-build run-main pilas colas listas