IDIR = ../ACE
LDIR = ../ACE

OBJS = main.o Config.o Index.o

index: $(OBJS)
	g++ -o Config.cpp Config.h -L$(LDIR) -I$(IDIR)
	g++ -o Index.cpp Index.h -L$(LDIR) -I$(IDIR)
	g++ -o main.cpp
	
clean:
	rm *.o
