CFLAGS= -Wall -fpic -coverage -lm -std=c99 -g

test: testme.c
	echo "testme.c:" >> testme.out
	gcc testme.c -lm -o testme $(CFLAGS)
	./testme >> /dev/null || true
	gcov testme.c >> testme.out
	./testme >> testme.out || true
	


clean:
	rm testme testme.c.gcov testme.gcda testme.gcno testme.out