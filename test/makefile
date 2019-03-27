TESTEXE = test.out

ODIR = ../obj
OBJS = $(addprefix $(ODIR)/, network.o reaction.o species.o)
TESTOBJ = $(addprefix $(ODIR)/, test.o)

SDIR = ../src
IDIR = ../include
DEPS = $(addprefix $(IDIR)/, network.hpp reaction.hpp species.hpp)

CC = g++ -std=c++11
CFLAGS = -c -I $(IDIR)
LFLAGS = 


$(TESTEXE): $(OBJS) $(TESTOBJ)
	$(CC) -o $@ $^ $(LFLAGS)

$(TESTOBJ): test.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 
