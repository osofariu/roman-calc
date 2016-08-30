SHELL = /bin/sh
CFLAGS=-Wall -g 
LDFLAGS= -Wall -L/usr/lib/x86_64-linux-gnu -L/lib/x86_64-linux-gnu -L /lib64  
LIBS= -l:libcheck.a  -lm -lrt -lpthread -lsubunit

TARGETS := test-roman test-strings
OBJDIR := obj
SRCDIR := src
INCLUDEDIR := include

all: test-roman test-strings
	./test-roman
	./test-strings

test-roman: $(OBJDIR)/roman.o $(OBJDIR)/strings.o $(OBJDIR)/test_roman.o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

test-strings: $(OBJDIR)/strings.o $(OBJDIR)/test_strings.o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

createobj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/test_roman.o: $(SRCDIR)/test_roman.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/roman.o: $(SRCDIR)/roman.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/test_strings.o: $(SRCDIR)/test_strings.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/strings.o: $(SRCDIR)/strings.c 
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<


valgrind: run
	valgrind --track-origins=yes ./run ${ARGS}

clean:
	rm -f $(TARGETS) $(OBJDIR)/*.o
