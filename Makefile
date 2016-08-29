SHELL = /bin/sh
CFLAGS=-Wall -g 
LDFLAGS= -Wall -L/usr/lib/x86_64-linux-gnu -L/lib/x86_64-linux-gnu -L /lib64  
LIBS= -l:libcheck.a  -lm -lrt -lpthread -lsubunit

.SUFFIXES:
.SUFFIXES: .c .o

TARGETS=roman
OBJDIR := obj
SRCDIR := src
INCDIR := include/

_SRCS := roman.c test_roman.c
SRCS := $(patsubst %,$(SRCDIR)/%,$(_SRCS))
OBJS := $(patsubst %,$(OBJDIR)/%,$(_SRCS:c=o))

all: run

run: roman
	./${TARGETS}

roman: $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@ 

createobj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | createobj
	$(CC) $(CFLAGS) -o $@ -I$(INCDIR) -c $<

valgrind: run
	valgrind --track-origins=yes ./run ${ARGS}

clean:
	rm -f $(TARGETS) $(OBJDIR)/*.o
