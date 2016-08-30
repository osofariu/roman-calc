SHELL = /bin/sh
CFLAGS=-Wall -g 
LDFLAGS= -Wall -L/usr/lib/x86_64-linux-gnu -L/lib/x86_64-linux-gnu -L /lib64  
LIBS= -l:libcheck.a  -lm -lrt -lpthread -lsubunit

TARGETS := test_roman_runner test_strings
OBJDIR := obj
SRCDIR := src
INCLUDEDIR := include

all: test_roman_runner test_strings
	./test_roman_runner
	./test_strings


test_roman_runner: $(OBJDIR)/test_roman_runner.o $(OBJDIR)/roman_to_int.o $(OBJDIR)/int_to_roman.o $(OBJDIR)/strings.o $(OBJDIR)/test_roman_to_int.o $(OBJDIR)/test_int_to_roman.o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

test_strings: $(OBJDIR)/strings.o $(OBJDIR)/test_strings.o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

createobj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/test_roman_runner.o: $(SRCDIR)/test_roman_runner.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/test_roman_to_int.o: $(SRCDIR)/test_roman_to_int.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/test_int_to_roman.o: $(SRCDIR)/test_int_to_roman.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/roman_to_int.o: $(SRCDIR)/roman_to_int.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/int_to_roman.o: $(SRCDIR)/int_to_roman.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/test_strings.o: $(SRCDIR)/test_strings.c
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

$(OBJDIR)/strings.o: $(SRCDIR)/strings.c 
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDEDIR) -c $<

clean:
	rm -f $(TARGETS) $(OBJDIR)/*.o
