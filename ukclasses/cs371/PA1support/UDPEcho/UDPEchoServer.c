/* 
 * Copyright (c) 2009 Morgan Kaufmann.
 * Authors: Michael J. Donahoo and Kenneth L. Calvert
 * All rights reserved.
 *
 * The authors and the Publisher DISCLAIM ALL EXPRESS AND IMPLIED 
 * WARRANTIES, including warranties of merchantability and fitness 
 * for any particular purpose. Your use or reliance upon any sample 
 * code or other information in this book will be at your own risk. 
 * No one should use any sample code (or illustrations) from this 
 * book in any software application without first obtaining competent 
 * legal advice.
 *
 * Adapted by Yang Xiao (xiaoy@uky.edu) for instructional purposes in 
 * CS371 at the University of Kentucky
 * 
 */

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "Practical.h"

int main(int argc, char *argv[]) {

  if (argc != 2) // Test for correct number of arguments
    DieWithUserMessage("Parameter(s)", "<Server Port/Service>");

  char *service = argv[1]; // First arg:  local port/service

  // Construct the server address structure
  struct addrinfo addrCriteria;                   // Criteria for address
  memset(&addrCriteria, 0, sizeof(addrCriteria)); // Zero out structure
  addrCriteria.ai_family = /*[YOUR CODE HERE]*/;              // Any address family
  addrCriteria.ai_flags = AI_PASSIVE;             // Accept on any address/port
  addrCriteria.ai_socktype = /*[YOUR CODE HERE]*/;           // Only datagram socket
  addrCriteria.ai_protocol = /*[YOUR CODE HERE]*/;          // Only UDP socket

  struct addrinfo *servAddr; // List of server addresses
  int rtnVal = getaddrinfo(NULL, service, &addrCriteria, &servAddr);
  if (rtnVal != 0)
    DieWithUserMessage("getaddrinfo() failed", gai_strerror(rtnVal));

  // Create socket for incoming connections
  int sock = socket(servAddr->ai_family, servAddr->ai_socktype, servAddr->ai_protocol);
  if (sock < 0)
    DieWithSystemMessage("socket() failed");

  // Bind to the local address
  // Bind to the local address
  // Use the "bind()" function, i.e., start with "bind(servSock,..."
  // [YOUR CODE HERE]

  // Free address list allocated by getaddrinfo()
  freeaddrinfo(servAddr);

  for (;;) { // Run forever
    struct sockaddr_storage clntAddr; // Client address
    // Set Length of client address structure (in-out parameter)
    socklen_t clntAddrLen = sizeof(clntAddr);

    // Block until receive message from a client
    char buffer[MAXSTRINGLENGTH]; // I/O buffer

    // Receive a message
    ssize_t numBytesRcvd; // Size of received message
    // Now use the "recvfrom()" function, which puts the received bytes into buffer and returns the number of bytes received
    // Start with "numBytesRcvd = recvfrom(sock, buffer,..."
    // [YOUR CODE HERE]  

    if (numBytesRcvd < 0)
      DieWithSystemMessage("recvfrom() failed");

    fputs("Handling client ", stdout);
    PrintSocketAddress((struct sockaddr *) &clntAddr, stdout);
    fputc('\n', stdout);
    visits++;
    printf("This server has been contacted %d time(s).\n", visits);

    // Send received datagram back to the client
    ssize_t numBytesSent;
    // Use the "sendto()" function, which sends the string in buffer to the server address and returns the number of bytes sent
    // Start with "numBytesSent = sendto(sock,..."
    // [YOUR CODE HERE]

    if (numBytesSent < 0)
      DieWithSystemMessage("sendto() failed)");
    else if (numBytesSent != numBytesRcvd)
      DieWithUserMessage("sendto()", "sent unexpected number of bytes");
  }
  // NOT REACHED
}
