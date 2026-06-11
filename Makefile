CXX = g++

CXXFLAGS = -std=c++17 -Wall

TARGET = poker

SRCS = Source/main.cpp \
       BackEnd/card.cpp \
       BackEnd/Game.cpp \
       BackEnd/Player.cpp \
       BackEnd/Deck.cpp \
       BackEnd/HandEvaluator.cpp \
       Screens/ProfileScreen.cpp \
       Screens/MenuScreen.cpp \
       Core/Application.cpp

OBJS = $(SRCS:.cpp=.o)

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS) -static-libgcc -static-libstdc++

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)