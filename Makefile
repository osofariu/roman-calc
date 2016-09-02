SHELL = /bin/sh
CFLAGS=-Wall -g 
LDFLAGS= -Wall -L/usr/lib/x86_64-linux-gnu -L/lib/x86_64-linux-gnu -L /lib64  
LIBS= -lcheck -lm -lrt -lpthread -lsubunit

TARGETS := roman_runner
OBJDIR := obj
SRCDIR := src
INCLUDEDIR := include

SOURCE_FILES := $(wildcard src/*.c)
SOURCE_NAMES := $(patsubst src/%,%,$(SOURCE_FILES))
OBJS :=  $(patsubst %,$(OBJDIR)/%,$(SOURCE_NAMES:c=o))

all: roman_runner
	./roman_runner tests

# will build the roman calculator main that runs all tests 
roman_runner: $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

create-obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | create-obj
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

clean:
	rm -f $(TARGETS) $(OBJDIR)/*.o
