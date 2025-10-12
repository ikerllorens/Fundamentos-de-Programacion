# Makefile para compilar todos los programas del repositorio Fundamentos de Programación
# Este Makefile compila todos los archivos .c en el repositorio excepto los que están rotos intencionalmente

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

# Directorios
FUNDAMENTOS_DIR = Fundamentos
IO_DIR = IO
ARRAYS_DIR = ARRAYS
POINTERS_DIR = POINTERS
PROGRAM_FLOW_DIR = PROGRAM\ FLOW
MAKEFILE_EXAMPLE_DIR = MAKEFILE_EXAMPLE
EJERCICIOS_DIR = EJERCICIOS
TERMINATOR_DIR = TERMINATOR

# Archivos de Fundamentos
FUNDAMENTOS_SOURCES = $(FUNDAMENTOS_DIR)/Comentarios.c \
                      $(FUNDAMENTOS_DIR)/EstructuraBasicaPrograma.c \
                      $(FUNDAMENTOS_DIR)/Tipos.c \
                      $(FUNDAMENTOS_DIR)/TiposEquivalencias.c \
                      $(FUNDAMENTOS_DIR)/Enteros.c

FUNDAMENTOS_OBJECTS = $(FUNDAMENTOS_SOURCES:.c=.o)
FUNDAMENTOS_EXECUTABLES = $(FUNDAMENTOS_SOURCES:.c=.out)

# Archivos de IO
IO_SOURCES = $(IO_DIR)/EjemploPrintf.c

IO_OBJECTS = $(IO_SOURCES:.c=.o)
IO_EXECUTABLES = $(IO_SOURCES:.c=.out)

# Archivos de ARRAYS
ARRAYS_SOURCES = $(ARRAYS_DIR)/Arreglos101.c \
                 $(ARRAYS_DIR)/ArreglosYReferencias.c

ARRAYS_OBJECTS = $(ARRAYS_SOURCES:.c=.o)
ARRAYS_EXECUTABLES = $(ARRAYS_SOURCES:.c=.out)

# Archivos de POINTERS
POINTERS_SOURCES = $(POINTERS_DIR)/Pointers.c \
                   $(POINTERS_DIR)/ValoresPorReferencia.c \
                   $(POINTERS_DIR)/direcciones_memoria.c

POINTERS_OBJECTS = $(POINTERS_SOURCES:.c=.o)
POINTERS_EXECUTABLES = $(POINTERS_SOURCES:.c=.out)

# Archivos de PROGRAM FLOW (directorio con espacio requiere tratamiento especial)
PROGRAM_FLOW_SOURCE = PROGRAM\ FLOW/IfExample.c
PROGRAM_FLOW_OBJECT = PROGRAM\ FLOW/IfExample.o
PROGRAM_FLOW_EXECUTABLE = PROGRAM\ FLOW/IfExample.out

# Archivos de EJERCICIOS
EJERCICIOS_SOURCES = $(EJERCICIOS_DIR)/Circulo.c \
                     $(EJERCICIOS_DIR)/ABECEDARIO/Abecedario.c \
                     $(EJERCICIOS_DIR)/SIMON_DICE/simon_dice.c

EJERCICIOS_OBJECTS = $(EJERCICIOS_SOURCES:.c=.o)
EJERCICIOS_EXECUTABLES = $(EJERCICIOS_SOURCES:.c=.out)

# Archivos de TERMINATOR
TERMINATOR_SOURCES = $(TERMINATOR_DIR)/TheTerminator.c \
                     $(TERMINATOR_DIR)/the_putter.c

TERMINATOR_OBJECTS = $(TERMINATOR_SOURCES:.c=.o)
TERMINATOR_EXECUTABLES = $(TERMINATOR_SOURCES:.c=.out)

# Proyecto MAKEFILE_EXAMPLE (compilación con múltiples archivos)
MAKEFILE_EXAMPLE_SOURCES = $(MAKEFILE_EXAMPLE_DIR)/main.c \
                           $(MAKEFILE_EXAMPLE_DIR)/suma.c \
                           $(MAKEFILE_EXAMPLE_DIR)/resta.c

MAKEFILE_EXAMPLE_OBJECTS = $(MAKEFILE_EXAMPLE_SOURCES:.c=.o)
MAKEFILE_EXAMPLE_EXECUTABLE = $(MAKEFILE_EXAMPLE_DIR)/calc.out

# ejemplo_xml_doc.c es solo documentación y no tiene main(), se compila solo como objeto
EJEMPLO_XML_DOC_SOURCE = $(MAKEFILE_EXAMPLE_DIR)/ejemplo_xml_doc.c
EJEMPLO_XML_DOC_OBJECT = $(EJEMPLO_XML_DOC_SOURCE:.c=.o)

# Todos los objetos y ejecutables
ALL_OBJECTS = $(FUNDAMENTOS_OBJECTS) $(IO_OBJECTS) $(ARRAYS_OBJECTS) \
              $(POINTERS_OBJECTS) $(PROGRAM_FLOW_OBJECT) $(EJERCICIOS_OBJECTS) \
              $(TERMINATOR_OBJECTS) $(MAKEFILE_EXAMPLE_OBJECTS) $(EJEMPLO_XML_DOC_OBJECT)

ALL_EXECUTABLES = $(FUNDAMENTOS_EXECUTABLES) $(IO_EXECUTABLES) $(ARRAYS_EXECUTABLES) \
                  $(POINTERS_EXECUTABLES) $(PROGRAM_FLOW_EXECUTABLE) $(EJERCICIOS_EXECUTABLES) \
                  $(TERMINATOR_EXECUTABLES) $(MAKEFILE_EXAMPLE_EXECUTABLE)

# Target principal: compilar todo
.PHONY: all
all: fundamentos io arrays pointers program-flow ejercicios terminator makefile-example

# Targets por directorio
.PHONY: fundamentos
fundamentos: $(FUNDAMENTOS_EXECUTABLES)
	@echo "✓ Fundamentos compilados correctamente"

.PHONY: io
io: $(IO_EXECUTABLES)
	@echo "✓ IO compilados correctamente"

.PHONY: arrays
arrays: $(ARRAYS_EXECUTABLES)
	@echo "✓ ARRAYS compilados correctamente"

.PHONY: pointers
pointers: $(POINTERS_EXECUTABLES)
	@echo "✓ POINTERS compilados correctamente"

.PHONY: program-flow
program-flow: $(PROGRAM_FLOW_EXECUTABLE)
	@echo "✓ PROGRAM FLOW compilados correctamente"

# Reglas especiales para PROGRAM FLOW (directorio con espacio)
$(PROGRAM_FLOW_OBJECT): $(PROGRAM_FLOW_SOURCE)
	$(CC) $(CFLAGS) -c $(PROGRAM_FLOW_SOURCE) -o $(PROGRAM_FLOW_OBJECT)

$(PROGRAM_FLOW_EXECUTABLE): $(PROGRAM_FLOW_OBJECT)
	$(CC) $(LDFLAGS) $(PROGRAM_FLOW_OBJECT) -o $(PROGRAM_FLOW_EXECUTABLE)

.PHONY: ejercicios
ejercicios: $(EJERCICIOS_EXECUTABLES)
	@echo "✓ EJERCICIOS compilados correctamente"

.PHONY: terminator
terminator: $(TERMINATOR_EXECUTABLES)
	@echo "✓ TERMINATOR compilados correctamente"

.PHONY: makefile-example
makefile-example: $(MAKEFILE_EXAMPLE_EXECUTABLE) $(EJEMPLO_XML_DOC_OBJECT)
	@echo "✓ MAKEFILE_EXAMPLE compilado correctamente"

# Reglas de compilación genéricas
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.out: %.o
	$(CC) $(LDFLAGS) $< -o $@

# Regla especial para calc.out (múltiples archivos objeto)
$(MAKEFILE_EXAMPLE_EXECUTABLE): $(MAKEFILE_EXAMPLE_OBJECTS)
	$(CC) $(LDFLAGS) $(MAKEFILE_EXAMPLE_OBJECTS) -o $@

# Target para limpiar archivos generados
.PHONY: clean
clean:
	@echo "Limpiando archivos generados..."
	@find . -name "*.o" -type f -delete
	@find . -name "*.out" -type f -delete
	@find . -name "*.exe" -type f -delete
	@echo "✓ Limpieza completada"

# Target para verificar compilación (compile check)
.PHONY: check
check: all
	@echo ""
	@echo "================================"
	@echo "Verificación de compilación completada"
	@echo "Todos los programas compilaron correctamente"
	@echo "================================"

# Target de ayuda
.PHONY: help
help:
	@echo "Makefile para Fundamentos de Programación"
	@echo ""
	@echo "Targets disponibles:"
	@echo "  all            - Compila todos los programas"
	@echo "  fundamentos    - Compila programas de Fundamentos"
	@echo "  io             - Compila programas de IO"
	@echo "  arrays         - Compila programas de ARRAYS"
	@echo "  pointers       - Compila programas de POINTERS"
	@echo "  program-flow   - Compila programas de PROGRAM FLOW"
	@echo "  ejercicios     - Compila programas de EJERCICIOS"
	@echo "  terminator     - Compila programas de TERMINATOR"
	@echo "  makefile-example - Compila el ejemplo de Makefile"
	@echo "  check          - Compila todo y verifica"
	@echo "  clean          - Elimina archivos generados (.o, .out, .exe)"
	@echo "  help           - Muestra esta ayuda"
