CC = tcc

install:
	${CC} -o figlet_timer figlet_timer.c
	mkdir -p ~/.local/bin/figlet_timer
	cp -f figlet_timer ~/.local/bin/figlet_timer/
uninstall:
	rm -rf ~/.local/bin/figlet_timer
