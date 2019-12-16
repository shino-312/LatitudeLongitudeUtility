CXX            = g++
CXXFLAGS       = -std=c++11 -Wall -g -O3 -Wpedantic
MKDIR_P        = mkdir -p

INC_DIRS       = -I/usr/include -I./inc
LIBS           = -L/usr/local/lib -lgtest -lpthread

BIN_ROOT       = ./bin/
SRC_ROOT       = ./src/
TEST_ROOT      = ./tests/

CXX_SRCS       = $(shell find $(SRC_ROOT) -name "*.cc")
CXX_OBJECTS    = $(addprefix $(BIN_ROOT), $(notdir $(CXX_FILES:.cc=.o)))

TEST_SRCS      = $(shell find $(TEST_ROOT) -name "*.cc")
TEST_OBJECTS   = $(addprefix $(BIN_ROOT), $(patsubst %.cc, %.o, $(notdir $(TEST_SRCS))))
TEST_TARGET    = $(BIN_ROOT)a.out

.DEFAULT_GOAL  := help

# See https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
.PHONY: help
help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: build
build: create_dirs $(TEST_TARGET)  ## Build test programs

.PHONY: clean
clean:  ## Delete binaries
	rm $(CXX_OBJECTS) $(TEST_OBJECTS)

.PHONY: test
test:  ## Run tests
	./$(TEST_TARGET)

.PHONY: create_dirs
create_dirs:  ## Create neccesary directories to run
	$(MKDIR_P) $(BIN_ROOT)


##################################################

$(TEST_TARGET): $(CXX_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -o $@ $^ $(LIBS)

# Path to find .cc files
VPATH = $(shell find $(SRC_ROOT) -type d) $(shell find $(TEST_ROOT) -type d)

$(BIN_ROOT)%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

