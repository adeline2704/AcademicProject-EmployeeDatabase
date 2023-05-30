proFile: helperA3.o mainA3.o printAll.o printOne.o lookOnId.o countEmployees.o sortEmployeesId.o lookOnFullName.o fireOne.o fireAll.o recruitEmployee.o
	gcc -Wall -std=c99 helperA3.o mainA3.o printAll.o printOne.o lookOnId.o countEmployees.o sortEmployeesId.o lookOnFullName.o fireOne.o fireAll.o recruitEmployee.o -o bin/proFile
helperA3.o: src/helperA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/helperA3.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printAll.c
recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -Wall -std=c99 -c src/recruitEmployee.c
printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printOne.c
lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookOnId.c
countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -Wall -std=c99 -c src/countEmployees.c
sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/sortEmployeesId.c
lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookOnFullName.c
fireOne.o: src/fireOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/fireOne.c
fireAll.o: src/fireAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/fireAll.c
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/mainA3.c
clean:
	rm *.o bin/proFile
