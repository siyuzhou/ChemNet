EXEC = test.out

ODIR = obj
OBJS = $(addprefix $(ODIR)/, test.o reaction.o species.o)

SDIR = src
IDIR = include
DEPS = $(addprefix $(IDIR)/, reaction.hpp species.hpp)

CC = g++
CFLAGS = -w -c -I $(IDIR)
LFLAGS = -w


$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 
