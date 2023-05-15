.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)

NAME2 = zad2
NAME3 = zad3
NAME4 = zad4
NAME5 = zad5
NAME6 = zad6

EXEC2 = $(NAME2).x
OBJS2 = $(NAME2).o
EXEC3 = $(NAME3).x  
OBJS3 = $(NAME3).o
EXEC4 = $(NAME4).x
OBJS4 = $(NAME4).o
EXEC5 = $(NAME5).x  
OBJS5 = $(NAME5).o
EXEC6 = $(NAME6).x
OBJS6 = $(NAME6).o

CO = g++
LD = $(CO)
%.o: %.cpp
	$(CO) -c $<
%.o: %.cpp
	$(CO) -c $<

$(EXEC2): $(OBJS2)
	$(LD) -o $@ $^
$(EXEC3): $(OBJS3)
	$(LD) -o $@ $^
$(EXEC4): $(OBJS4)
	$(LD) -o $@ $^
$(EXEC5): $(OBJS5)
	$(LD) -o $@ $^
$(EXEC6): $(OBJS6)
	$(LD) -o $@ $^

run2: $(EXEC2)
	./$(EXEC2)
run3: $(EXEC3)
	./$(EXEC3)
run4: $(EXEC4)
	./$(EXEC4)
run5: $(EXEC5)
	./$(EXEC5)
run6: $(EXEC6)
	./$(EXEC6)

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x *.txt core core* a.out; rm -rf ${LIB_DIR}
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

