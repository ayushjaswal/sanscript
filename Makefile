SRC=backend/Lexer.cpp
BUILD=build
all:
	g++ $(SRC) -o $(BUILD)/comp.o
