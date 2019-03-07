CFLAGS= -Wall -fpic -coverage -lm -std=c99 -g

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

runrandomtests: randomtestadventurer.c
	echo "Result for running randomtestadventurer:" > randomtestadventurer.out
	gcc rngs.c dominion.c randomtestadventurer.c -o testing $(CFLAGS)
	./testing >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	echo "dominion.c.gcov file:" >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

	echo "Result for running randomtestcard1:" > randomtestcard1.out
	gcc rngs.c dominion.c randomtestcard1.c -o testing  $(CFLAGS) 
	./testing >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	echo "dominion.c.gcov file:" >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

	echo "Result for running randomtestcard2:" > randomtestcard2.out
	gcc rngs.c dominion.c randomtestcard2.c -o testing $(CFLAGS)
	./testing >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	echo "dominion.c.gcov file:" >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out
	
unittestresult: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
	echo "Result for running unit tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc test_helper.c rngs.c dominion.c unittest1.c -o unittest1 $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittest1.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc test_helper.c rngs.c dominion.c unittest2.c -o unittest2 $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittest2.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc test_helper.c rngs.c dominion.c unittest3.c -o unittest3 $(CFLAGS) 
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittest3.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc test_helper.c rngs.c dominion.c unittest4.c -o unittest4 $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittest4.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc test_helper.c rngs.c dominion.c cardtest1.c -o cardtest1 $(CFLAGS) 
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> cardtest1.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc test_helper.c rngs.c dominion.c cardtest2.c -o cardtest2 $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> cardtest2.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc test_helper.c rngs.c dominion.c cardtest3.c -o cardtest3 $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> cardtest3.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc  test_helper.c rngs.c dominion.c cardtest4.c -o cardtest4 $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> cardtest4.out

	echo "greathalltestcard.c" >> unittestresults.out
	gcc test_helper.c rngs.c dominion.c greathallcardtest.c -o greathallcardtest $(CFLAGS)
	./greathallcardtest >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> greathallcardtest.out

	echo "councilroomcardtest.c:" >> unittestresults.out
	gcc  test_helper.c rngs.c dominion.c councilroomcardtest.c -o councilroomcardtest $(CFLAGS)
	./councilroomcardtest >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> councilroomcardtest.out


allusertest: runrandomtests unittestresult

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
