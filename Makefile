SHELL = /bin/sh
CFLAGS=-Wall -g 
LDFLAGS= -Wall -L/usr/lib/x86_64-linux-gnu -L/lib/x86_64-linux-gnu -L /lib64  
LIBS= -l:libcheck.a  -lm -lrt -lpthread -lsubunit

TARGETS := test_roman_to_int test_strings
OBJDIR := obj
SRCDIR := src
INCLUDEDIR := include

all: test_roman_to_int test_strings
	./test_roman_to_int
	./test_strings

test_roman_to_int: $(OBJDIR)/roman_to_int.o $(OBJDIR)/strings.o $(OBJDIR)/test_roman_to_int.o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

test_strings: $(OBJDIR)/strings.o $(OBJDIR)/test_strings.o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

createobj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/test_roman_to_int.o: $(SRCDIR)/test_roman_to_int.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/roman_to_int.o: $(SRCDIR)/roman_to_int.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/test_strings.o: $(SRCDIR)/test_strings.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/strings.o: $(SRCDIR)/strings.c 
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<


valgrind: run
	valgrind --track-origins=yes ./run ${ARGS}

clean:
	rm -f $(TARGETS) $(OBJDIR)/*.o
