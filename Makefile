all:
	g++ main.cpp sort.cpp
faker:
	pip3 install Faker
	python3.6 input-generator.py;
tester:
	sort saida.dat -o testeSaida.dat
	diff saida.dat testeSaida.dat
