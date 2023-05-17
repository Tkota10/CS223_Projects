# C compiler and flags
CC     = gcc
CFLAGS = -std=c17 -Wall -Werror -pedantic -g

# Targets
HookBook: hookbook.o libhookbook.o pirate_list.o pirate.o
	${CC} ${CFLAGS} -o $@ $^

hookbook.o: hookbook.c pirate_list.h pirate.h libhookbook.h
	${CC} ${CFLAGS} -c -o $@ $<

libhookbook.o: libhookbook.c pirate_list.h pirate.h
	${CC} ${CFLAGS} -c -o $@ $<

pirate_list.o: pirate_list.c pirate_list.h pirate.h
	${CC} ${CFLAGS} -c -o $@ $<

pirate.o: pirate.c pirate.h
	${CC} ${CFLAGS} -c -o $@ $<

clean :
	rm *.o HookBook

     