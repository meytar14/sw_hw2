all: main
main: main.o myBanklib.a
	gcc -Wall  main.o myBanklib.a -o main

main.o: main.c 
	gcc -Wall -c  main.c -o main.o

myBanklib.a: myBank.o
	ar -rcs myBanklib.a myBank.o

myBank.o: myBank.c myBank.h
	gcc -Wall -c myBank.c -o myBank.o

clean:
	rm *.o *.a main

