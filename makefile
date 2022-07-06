CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -g
SRC_DUMP = students_dump.c
SRC_QUERY = students_task.c

dump:
	$(CC) $(CFLAGS) $(SRC_DUMP) -o "dump.bin"

query:
	$(CC) $(CFLAGS) $(SRC_QUERY) -o "query.bin"

clean:
	rm "dump.bin" "query.bin"

