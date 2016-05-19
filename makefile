TARGET=a.out  
NOMAKEDIR=
SRCS=$(shell find * -name "*.cpp")  
OBJS=$(patsubst %.cpp, %.o, $(SRCS))  
INCLUDE=$(addprefix -I./,$(filter-out $(NOMAKEDIR), $(shell find * -type d)))  
CXX=g++  
  
all: $(TARGET)  
	  
$(TARGET): $(OBJS)  
	 $(CXX) -o $@ $(OBJS)  
	   
%.o : %.cpp  
	 $(CXX) $(INCLUDE) -c -o $@ $<  
	   
depend:  
	 makedepend -Y -- $(INCLUDE) -- $(SRCS)  
	   
clean:  
	 rm -f $(TARGET) $(OBJS)  
	   
remake:  
	 make clean && make 
