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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Practical.h"

static const int MAXPENDING = 5; // Maximum outstanding connection requests

int main(int argc, char *argv[]) {

  if (argc != 2) // Test for correct number of arguments
    DieWithUserMessage("Parameter(s)", "<Server Port>");

  in_port_t servPort = atoi(argv[1]); // First arg:  local port

 
  // Create a reliable, stream socket using TCP for incoming connections
  int servSock; // Socket descriptor for server
  // Use the "socket()" function, i.e., start with "servSock = socket(..."
  // [YOUR CODE HERE]

  // Construct local address structure
  struct sockaddr_in servAddr;                  // Local address
  memset(&servAddr, 0, sizeof(servAddr));       // Zero out structure
  servAddr.sin_family = AF_INET;                // IPv4 address family
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface
  servAddr.sin_port = htons(servPort);          // Local port

  // Bind to the local address
  // Use the "bind()" function, i.e., start with "bind(servSock,..."
  // [YOUR CODE HERE]

  // Mark the socket so it will listen for incoming connections
  if (listen(servSock, MAXPENDING) < 0)
    DieWithSystemMessage("listen() failed");

  while (1) { // Run forever
    struct sockaddr_in clntAddr; // Client address
    // Set length of client address structure (in-out parameter)
    socklen_t clntAddrLen = sizeof(clntAddr);

    // Wait for a client to connect
    int clntSock; // client socket
    // Use the "accept()" function, i.e., start with "clntSock = accept(..."
    // [YOUR CODE HERE]

    char clntName[INET_ADDRSTRLEN]; // String to contain client address
    if (inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr, clntName, sizeof(clntName)) != NULL)
      printf("Handling client %s/%d\n", clntName, ntohs(clntAddr.sin_port));
    else
      puts("Unable to get client address");

    HandleTCPClient(clntSock);
    visits++;
    printf("This server has been contacted %d time(s).\n", visits);
  }
  // NOT REACHED
}