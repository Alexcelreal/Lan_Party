.PHONY: clean run

run: lanParty
	./lanParty date/t1/c.in date/t1/d.in r.out

build: main.c
	gcc TheLastEightAVL.c TheLastEightBST.c Stacks.c Queues.c theRealCompetition.c eliminateLowPoints.c Lists.c ReadfromFile.c main.c -Wall -o lanParty

clean:
	rm -f lanParty
	rm -f r.out