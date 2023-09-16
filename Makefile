dma:dma.o
	gcc -g3 -Wall dma.o -o dma.exe
dma.o:dma.c
	gcc -g3 -c -Wall dma.c -o dma.o
clear:
	rm *.o
clean:
	rm *.o *.exe