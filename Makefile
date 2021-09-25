src = $(wildcard ./*.c)
obj = $(patsubst %.c, %.o, $(src))
target = mytimeserver
CC = gcc
$(target) : $(obj)
	$(CC) $(obj) -o $(target) -lpthread

%.o : %.c
	$(CC) -c $< -o $@

.PHONY : clean
clean :
	rm -rf $(obj) $(target)

.PHONY : cleanobj
cleanobj :
	rm -rf $(obj)