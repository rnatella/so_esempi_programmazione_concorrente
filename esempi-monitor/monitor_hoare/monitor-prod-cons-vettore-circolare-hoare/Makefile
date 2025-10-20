eseguibile: main.o prodcons.o monitor_hoare.o
	gcc -o eseguibile  main.o prodcons.o monitor_hoare.o

main.o: main.c prodcons.h
	gcc -o main.o -c   main.c

prodcons.o: prodcons.c prodcons.h
	gcc -o prodcons.o -c   prodcons.c

monitor_hoare.o: monitor_hoare.c monitor_hoare.h
	gcc -o monitor_hoare.o -c   monitor_hoare.c

clean:
	rm -f eseguibile
	rm -f *.o
