# Object files that we need for Tokenizer
OBJS = tokenizer.o uimain.o history.o

# Flags to compile
CFLAGS = -g -O3

# Our first target built
all: Tokenizer

Tokenizer: $(OBJS)
	cc -o Tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o Tokenizer

run: Tokenizer
	./Tokenizer
