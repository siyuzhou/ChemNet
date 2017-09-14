EXEC = test.out

ODIR = obj
OBJS = $(addprefix $(ODIR)/, test.o network.o reaction.o species.o)

SDIR = src
IDIR = include
DEPS = $(addprefix $(IDIR)/, network.hpp reaction.hpp species.hpp)

CC = g++ -std=c++11
CFLAGS = -c -I $(IDIR)
LFLAGS = 


$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 
