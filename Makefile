CC = g++
CFLAGS = -g -std=c++11

a.out: MyTime.o MyTime.h runtime.o runtime.h Runjournal.o Runjournal.h main.o
	$(CC) $(CFLAGS) MyTime.o runtime.o Runjournal.o main.o -o a.out

MyTime.o: MyTime.cc MyTime.h
	$(CC) -c $(CFLAGS) MyTime.cc -o MyTime.o

RunJournal.o: Runjournal.cc Runjournal.h
	$(CC) -c $(CFLAGS) Runjournal.cc -o Runjournal.o

runtime.o: runtime.cc runtime.h
	$(CC) -c $(CFLAGS) runtime.cc -o runtime.o

main.o: main.cc MyTime.h
	$(CC) -c $(CFlAGS) main.cc -o main.o