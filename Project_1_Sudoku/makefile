Sukodu: main.o Make_map.o CheckPosition.o Menu.o Time.o Step.o
	g++ -o Sukodu main.o Make_map.o CheckPosition.o Menu.o Time.o Step.o -lncurses

Sukodu.o:main.cpp
	g++ -c main.cpp

CheckPosition.o:CheckPosition.cpp CheckPosition.h
	g++ -c CheckPosition.cpp

Menu.o:Menu.cpp Menu.h
	g++ -c Menu.cpp

Time.o:Time.cpp Time.h
	g++ -c Time.cpp

Stenp.o:Step.cpp Step.h
	g++ -c Step.cpp

clean:
	rm *.o Sukodu

