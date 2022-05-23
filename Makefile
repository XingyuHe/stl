# change the default compiler with the one
# that supports C++20 modules feature
CC='g++-11'
# CFLAGS = -g -O2 --std=c++20 -c
CFLAGS = -g -Wall --std=c++20 -c

LDFLAGS = -g

# optional library if we want to include
# LDLIBS = -larmadillo -ljpeg -lpng

export CPATH=lib/include
export LIBRARY_PATH=lib/lib


main: main.o
	$(CC) main.o -o main $(LDFLAGS) $(LDLIBS)

main.o: main.cpp vector.h
	$(CC) $(CFLAGS) main.cpp vector.h


.PHONY: clean
clean:
	rm -rf *.o main *.out *.pcm