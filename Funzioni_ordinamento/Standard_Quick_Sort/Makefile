Verifica: Verifica.o Standard_Quick_Sort.o
	gcc -g -o Verifica Verifica.o Standard_Quick_Sort.o && rm *.o
Verifica.o: Verifica.c Verifica.h
	gcc -g -c Verifica.c
Standard_Quick_Sort.o: Standard_Quick_Sort.c Verifica.h
	gcc -g -c Standard_Quick_Sort.c
