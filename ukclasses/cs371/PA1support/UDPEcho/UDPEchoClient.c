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

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include "Practical.h"

int main(int argc, char *argv[]) {

  if (argc < 3 || argc > 4) // Test for correct number of arguments
    DieWithUserMessage("Parameter(s)", "<Server Address/Name> <Echo Word> [<Server Port/Service>]");

  char *server = argv[1];     // First arg: server address/name
  char *echoString = argv[2]; // Second arg: word to echo

  size_t echoStringLen = strlen(echoString);
  if (echoStringLen > MAXSTRINGLENGTH) // Check input length
    DieWithUserMessage(echoString, "string too long");

  // Third arg (optional): server port/service
  char *servPort = (argc == 4) ? argv[3] : "echo";

  // Tell the system what kind(s) of address info we want
  struct addrinfo addrCriteria;                   // Criteria for address match
  memset(&addrCriteria, 0, sizeof(addrCriteria)); // Zero out structure

  addrCriteria.ai_family =   /*[YOUR CODE HERE]*/;             // Any address family
  addrCriteria.ai_socktype = /*[YOUR CODE HERE]*/;          // Only datagram sockets
  addrCriteria.ai_protocol = /*[YOUR CODE HERE]*/;         // Only UDP protocol

  // Get address(es)
  struct addrinfo *servAddr; // List of server addresses
  int rtnVal = getaddrinfo(server, servPort, &addrCriteria, &servAddr);
  if (rtnVal != 0)
    DieWithUserMessage("getaddrinfo() failed", gai_strerror(rtnVal));

  // Create a datagram/UDP socket identified by sock
  int sock = socket(servAddr->ai_family, servAddr->ai_socktype, servAddr->ai_protocol); // Socket descriptor for client
  
  if (sock < 0)
    DieWithSystemMessage("socket() failed");

  // Send the string to the server
  // Use the "sendto()" function, which sends echoString to the server address and returns the number of bytes sent
  // Start with "ssize_t numBytes = sendto(sock,..."
  // [YOUR CODE HERE]

  if (numBytes < 0)
    DieWithSystemMessage("sendto() failed");
  else if (numBytes != echoStringLen)
    DieWithUserMessage("sendto() error", "sent unexpected number of bytes");

  
  struct sockaddr_storage fromAddr; // Source address of server
  // Set length of from address structure (in-out parameter)
  socklen_t fromAddrLen = sizeof(fromAddr);
  char buffer[MAXSTRINGLENGTH + 1]; // I/O buffer

  // Receive a response
  // Now use the "recvfrom()" function, which puts the received bytes into buffer and returns the number of bytes received
  // Start with "numBytes = recvfrom(sock, buffer,..."
  // [YOUR CODE HERE]  

  if (numBytes < 0)
    DieWithSystemMessage("recvfrom() failed");
  else if (numBytes != echoStringLen)
    DieWithUserMessage("recvfrom() error", "received unexpected number of bytes");

  // Verify reception from expected source
  if (!SockAddrsEqual(servAddr->ai_addr, (struct sockaddr *) &fromAddr))
    DieWithUserMessage("recvfrom()", "received a packet from unknown source");

  freeaddrinfo(servAddr);

  buffer[echoStringLen] = '\0';     // Null-terminate received data

  // Print the echoed string, starting with "Received" ending with a new line
  // [YOUR CODE HERE]

  close(sock);
  exit(0);
}
