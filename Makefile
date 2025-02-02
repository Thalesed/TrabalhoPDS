# Definir o compilador e as flags
CXX = g++
CXXFLAGS = -std=c++17	-g -Wall -Iinclude	-Iinclude/manipular_arquivos	-Iinclude/login	-Iinclude/menu	-Iinclude/set	-Iinclude/get	-Iinclude/modificar	-Iinclude/delete	-IArquivos_de_dados	-Iinclude/add_file

# Definir o nome do executável
TARGET = programa

# Lista de arquivos fonte
SRCS =	$(wildcard src/*.cpp)	$(wildcard src/manipular_arquivos/*.cpp)	$(wildcard	src/login/*.cpp)	$(wildcard	src/menu/*.cpp)	$(wildcard	src/set/*.cpp)	$(wildcard	src/get/*.cpp)	$(wildcard	src/mod/*.cpp)	$(wildcard	src/delete/*.cpp)	$(wildcard	src/add_file/*.cpp)
SRCS_O =	$(SRCS:.cpp=.o)


# Regra pra criar o arquivo.exe
bistrosystem:	$(SRCS_O)
	$(CXX)	main.cpp	$(CXXFLAGS)	$^	-o	$@.exe

# Regra para compilar os arquivos .cpp para .o
comp_o: $(SRCS)
	$(CXX) $(CXXFLAGS)	-c	$<	-o	$@

# Limpeza dos arquivos gerados
clean:
	rm -f $(SRCS_O) bistrosystem.exe

# Definir regras especiais
.PHONY: all clean fclean re
