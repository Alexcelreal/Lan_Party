.PHONY: clean run

run: lanParty
	./lanParty date/t15/c.in date/t15/d.in r.out

build: main.c
	gcc TheLastEightAVL.c TheLastEightBST.c Stacks.c Queues.c theRealCompetition.c eliminateLowPoints.c Lists.c ReadfromFile.c main.c -Wall -o lanParty

clean:
	rm -f lanParty
	rm -f r.out