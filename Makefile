backprop:
	g++ -Wall -Werror -std=c++17 backpropClassifier/*.cpp -o backprop.o

line:
	echo ---------------------------------------------

run:
	./backprop.o ./datasets/debug.csv

runh:
	./backprop.o ./datasets/homework.csv

clean:
	rm backprop.o
