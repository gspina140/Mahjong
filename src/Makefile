CFLAGS := -lGL -lX11 -lGLEW -lglut -lGLU -lm 
C_TARGETS := mahjong
C_SOURCES := $(wildcard *.[ch])
objects = main.o shader.o Mahjong.o readBMP.o texturing.o

.PHONY: clean

all: $(C_TARGETS)

readBMP.o: readBMP.c readBMP.h
shader.o: shader.c shader.h
Mahjong.o: Mahjong.c Mahjong.h
texturing.o: texturing.c texturing.h
main.o: main.c shader.h Mahjong.h texturing.h data.h

mahjong: main.o shader.o Mahjong.o readBMP.o texturing.o
	$(CC) $(objects) -o mahjong $(CFLAGS)
clean:
	@rm -rf $(C_TARGETS) *.zip *.o *.dSYM *~
