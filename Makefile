#Kopiera timer till localbin/timer
#linka -lncurses
CC = tcc

install:
	${CC} -o ttytimer -lncurses ttytimer.c
	mkdir -p ~/.local/bin/ttytimer
	cp -f ttytimer ~/.local/bin/ttytimer/
uninstall:
	rm -rf ~/.local/bin/ttytimer
