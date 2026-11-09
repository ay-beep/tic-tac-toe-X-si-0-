CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Fișierele obiect pentru biblioteca statică (clasele de date)
LIB_OBJS = point.o player.o board.o
LIB_NAME = libgame.a

# Fișierele obiect pentru restul aplicației
APP_OBJS = main.o game_engine.o listener.o painter.o renderer.o

TARGET = TicTacToe.exe

all: $(TARGET)

# Regula pentru crearea bibliotecii statice
$(LIB_NAME): $(LIB_OBJS)
	ar rcs $@ $^

# Regula pentru generarea executabilului legând biblioteca statică
$(TARGET): $(APP_OBJS) $(LIB_NAME)
	$(CXX) $(CXXFLAGS) -o $@ $(APP_OBJS) $(LIB_NAME)

# Regula generală de compilare pentru fișiere .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Curățarea fișierelor generate
clean:
	rm -f *.o $(LIB_NAME) $(TARGET)