all:
	g++ main.cpp sort.cpp
faker:
	pip install Faker
	python3.6 input-generator.py;
