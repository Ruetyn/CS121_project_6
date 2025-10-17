heapOfStudents: heapOfStudents.o Student.o Address.o Date.o
	g++ -g heapOfStudents.o Student.o Address.o Date.o -o heapOfStudents

heapOfStudents.o: heapOfStudents.cpp student.h address.h date.h
	g++ -c -g heapOfStudents.cpp

Student.o: Student.cpp student.h address.h date.h
	g++ -c -g Student.cpp

Address.o: Address.cpp address.h
	g++ -c -g Address.cpp

Date.o: Date.cpp date.h
	g++ -c -g Date.cpp

run: heapOfStudents
	./heapOfStudents

debug: heapOfStudents
	gdb ./heapOfStudents

valgrind: heapOfStudents
	valgrind --leak-check=full ./heapOfStudents

clean:
	rm -f *.o
	rm -f heapOfStudents
