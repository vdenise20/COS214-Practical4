CXX = g++
CXXFLAGS = -g -std=c++17
SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TARGET = Practical3 
ZIP_FILE = u23676150.zip

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ_FILES) $(TARGET)

zip:
	zip -u $(ZIP_FILE) $(SRC_FILES) *.h Makefile

clear:
	clear

# # Define compiler and compiler flags
# CXX = g++
# CXXFLAGS = -g -std=c++17

# # Define sources and objects
# SRCS = main.cpp \
#        LegionFactory.cpp \
# 	   LegionUnit.cpp \
#        WoodlandFactory.cpp \
#        RiverBankFactory.cpp \
#        OpenFieldFactory.cpp \
#        TacticalPlanner.cpp \
# 	   TacticalCommand.cpp \
# 	   TacticalMemento.cpp \
#        WarArchives.cpp \
#        Legion.cpp \
#        Infantry.cpp \
#        Cavalry.cpp \
#        Artillery.cpp \
#        Flanking.cpp \
#        Fortification.cpp \
#        Ambush.cpp
# OBJS = $(SRCS:.cpp=.o)

# # Define the executable
# TARGET = practical3

# # Rule to link the object files and create the executable
# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# # Rule to compile source files into object files
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Rule to clean up compiled files
# clean:
# 	rm -f $(OBJS) $(TARGET)

# # Rule to run the program
# run: $(TARGET)
# 	./$(TARGET)
