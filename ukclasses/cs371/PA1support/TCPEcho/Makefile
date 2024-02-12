CC = gcc
CFLAGS = -g -Wall

all: TCPEchoServer TCPEchoClient

TCPEchoServer: TCPEchoServer.c TCPServerUtility.c DieWithMessage.c
	$(CC) $(CFLAGS) -o $@ -std=gnu99 $^ 

TCPEchoClient: TCPEchoClient.c DieWithMessage.c
	$(CC) $(CFLAGS) -o $@ -std=gnu99 $^ 

clean:
	-rm -f *.o *~ *core* TCPEchoServer TCPEchoClient
