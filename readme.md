##Installing instructions:
	sudo apt install make gcc
	make
	sudo make install

##Usage:
	memthief [memory in percentage] [time]

###Examples:
	memthief 10, allocates 10% of total system memory.
	
	memthief 100 1, first tries to allocate 100% of total system memory and closes after one second.

