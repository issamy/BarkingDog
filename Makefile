all: BarkingDog
	
BarkingDog: RCSwitch.o BarkingDog.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi
	
clean:
	$(RM) *.o BarkingDog  
