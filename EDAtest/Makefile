cc = gcc
prom = edatest
deps = $(shell find ./ -name "*.h")
CFLAGS=-Wall -std=gnu99 -g
INC = -I./user -I./user/testcase -I./driver -I./common
src = $(shell find ./ -name "*.c")
obj = $(src:%.c=%.o) 


$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

%.o: %.c $(deps)
	$(cc) -c $< $(CFLAGS) $(INC) -o $@

clean:
	rm -rf $(obj) $(prom)

