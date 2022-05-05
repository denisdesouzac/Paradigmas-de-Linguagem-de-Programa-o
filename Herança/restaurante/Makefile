CXX = g++
CXXFLAGS = -Wall -Wconversion
BINS = restaurante

restaurante: item.o bebida.o prato.o sobremesa.o pedido.o main.o
	$(CXX) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f *.o *~ $(BINS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

