

UNO:uno_driver.o game_utils.o deck_utils.o
	gcc -o UNO.exe uno_driver.o game_utils.o deck_utils.o

uno_driver.o:uno_driver.c
	gcc -c uno_driver.c

game_utils.o:game_utils.c
	gcc -c game_utils.c

deck_utils.o:deck_utils.c
	gcc -c deck_utils.c
