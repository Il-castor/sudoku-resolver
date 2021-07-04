CXXFLAGS=-Wall

OBJ = main.o 

All: $(OBJ)
	g++ -o All $(OBJ)

main.o: main.cc
	g++ -c  main.cc

.PHONY: clean cleanall
.clean:
	rm -f *.o
.cleanall:
	rm -f All *.o