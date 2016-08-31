SHELL = /bin/sh
CFLAGS=-Wall -g 
LDFLAGS= -Wall -L/usr/lib/x86_64-linux-gnu -L/lib/x86_64-linux-gnu -L /lib64  
LIBS= -lcheck -lm -lrt -lpthread -lsubunit

TARGETS := test_roman_runner test_char_operations
OBJDIR := obj
SRCDIR := src
INCLUDEDIR := include

ROMAN_SOURCE_FILES := $(wildcard src/*roman*.c) char_operations.c
ROMAN_SOURCE_NAMES := $(patsubst src/%,%,$(ROMAN_SOURCE_FILES))
ROMAN_OBJS :=  $(patsubst %,$(OBJDIR)/%,$(ROMAN_SOURCE_NAMES:c=o))

$(info $$ROMAN_SOURCE_FILES is [${ROMAN_SOURCE_FILES}])
$(info $$ROMAN_SOURCENAMES is [${ROMAN_SOURCE_NAMES}])
$(info $$ROMAN_OBJS is [${ROMAN_OBJS}])

all: test_roman_runner test_char_operations
	./test_roman_runner
	./test_char_operations

# will build the roman calculator main that runs all tests 
test_roman_runner: $(ROMAN_OBJS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

create-obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | create-obj
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

# will buile the string library main that run all tests
test_char_operations: $(OBJDIR)/char_operations.o $(OBJDIR)/test_char_operations.o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

clean:
	rm -f $(TARGETS) $(OBJDIR)/*.o
