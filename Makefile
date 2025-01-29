# Definir o compilador e as flags
CXX = g++
CXXFLAGS = -std=c++17	-g -Wall -Iinclude	-Iinclude/manipular_arquivos	-Iinclude/login	-Iinclude/menu	-Iinclude/set	-Iinclude/get	-Iinclude/mod	-Iinclude/delete

# Definir o nome do executável
TARGET = programa

# Lista de arquivos fonte
SRCS = $(wildcard src/*.cpp)	$(wildcard src/manipular_arquivos/*.cpp)	$(wildcard	src/login/*.cpp)	$(wildcard	src/menu/*.cpp)	$(wildcard	src/set/*.cpp)	$(wildcard	src/get/*.cpp)	$(wildcard	src/mod/*.cpp)	$(wildcard	src/delete/*.cpp)
SRCS_O = $(wildcard src/*.o)	$(wildcard src/manipular_arquivos/*.o)	$(wildcard	src/login/*.o)	$(wildcard	src/menu/*.o)	$(wildcard	src/set/*.o)	$(wildcard	src/get/*.o)	$(wildcard	src/mod/*.o)	$(wildcard	src/delete/*.o)

# Gerar os arquivos objetos (.o) a partir dos arquivos fonte
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(TARGET)

# Como compilar o executável a partir dos arquivos objetos
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o

# Regra para compilar os arquivos .cpp para .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para gerar uma biblioteca estática
lib: $(SRCS_O)
	ar	rcs lib.a $(SRCS_O)

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

# Limpeza completa
fclean: clean
	rm -f $(TARGET)

# Recompilar tudo
re: fclean all

# Definir regras especiais
.PHONY: all clean fclean re
