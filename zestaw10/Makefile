.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)

NAME1 = zad1
NAME2 = zad2
NAME3 = zad3

EXEC1 = $(NAME1).x
OBJS1 = $(NAME1).o
EXEC2 = $(NAME2).x
OBJS2 = $(NAME2).o
EXEC3 = $(NAME3).x  
OBJS3 = $(NAME3).o

CO = g++
LD = $(CO)
%.o: %.cpp
	$(CO) -c $<
%.o: %.cpp
	$(CO) -c $<

$(EXEC1): $(OBJS1)
	$(LD) -o $@ $^
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $^
$(EXEC3): $(OBJS3)
	$(LD) -o $@ $^

run1: $(EXEC1)
	./$(EXEC1)
run2: $(EXEC2)
	./$(EXEC2)
run3: $(EXEC3)
	./$(EXEC3)

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x *.txt core core* a.out; rm -rf ${LIB_DIR}
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

