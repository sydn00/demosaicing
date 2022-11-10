all:
	g++ main.cpp -o demosaicing

run:
	./demosaicing

clean:
	rm demosaicing