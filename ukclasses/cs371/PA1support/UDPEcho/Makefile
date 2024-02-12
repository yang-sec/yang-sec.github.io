CC = gcc
CFLAGS = -g -Wall

all: UDPEchoServer UDPEchoClient

UDPEchoServer: UDPEchoServer.c DieWithMessage.c AddressUtility.c
	$(CC) $(CFLAGS) -o $@ -std=gnu99 $^ 

UDPEchoClient: UDPEchoClient.c DieWithMessage.c AddressUtility.c
	$(CC) $(CFLAGS) -o $@ -std=gnu99 $^ 

clean:
	-rm -f *.o *~ *core* UDPEchoServer UDPEchoClient
