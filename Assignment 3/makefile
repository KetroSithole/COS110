Task1:	*.o

	g++ -o Task1 *.o

*.o:	*.cpp

	g++ -c *.cpp

run:

	./Task1

clean:

	rm *.o *.zip Task1 


zip:

	zip -r Task2.zip *.cpp *.h --exclude=*PalmVein.cpp* --exclude=*PalmVein.h* --exclude="main.cpp"