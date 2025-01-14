# Definir o compilador e as flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Definir o nome do executável
TARGET = programa

# Lista de arquivos fonte
SRCS = src/cardapio.cpp src/cliente.cpp src/gerente.cpp src/historico.cpp \
       src/pedido.cpp src/prato.cpp src/produto.cpp src/user.cpp main.cpp

# Gerar os arquivos objetos (.o) a partir dos arquivos fonte
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(TARGET)

# Como compilar o executável a partir dos arquivos objetos
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Regra para compilar os arquivos .cpp para .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

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
