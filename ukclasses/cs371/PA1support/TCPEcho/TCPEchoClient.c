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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Practical.h"

int main(int argc, char *argv[]) {

  if (argc < 3 || argc > 4) // Test for correct number of arguments
    DieWithUserMessage("Parameter(s)", "<Server Address> <Echo Word> [<Server Port/Service>]");

  char *servIP = argv[1];     // First arg: server address
  char *echoString = argv[2]; // Second arg: string to echo
  in_port_t servPort = (argc == 4) ? atoi(argv[3]) : 7;   // Third arg (optional): server port (numeric).  7 is well-known echo port

  // Create a reliable, stream socket using TCP
  int sock;
  // Use the "socket()" function, i.e., start with "sock = socket(..."
  // [YOUR CODE HERE]

  // Construct the server address structure
  struct sockaddr_in servAddr;            // Server address
  memset(&servAddr, 0, sizeof(servAddr)); // Zero out structure
  servAddr.sin_family = AF_INET;          // IPv4 address family
  // Convert address
  int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
  if (rtnVal == 0)
    DieWithUserMessage("inet_pton() failed", "invalid address string");
  else if (rtnVal < 0)
    DieWithSystemMessage("inet_pton() failed");
  servAddr.sin_port = htons(servPort);    // Server port

  // Establish the connection to the echo server
  // Use the "connect()" function
  // [YOUR CODE HERE]

  size_t echoStringLen = strlen(echoString); // Determine input length

  // Send the echoString to the server
  // Use the "send()" function, which returns the number of bytes sent
  // start with "size_t numBytes = send(..."
  // [YOUR CODE HERE]

  if (numBytes < 0)
    DieWithSystemMessage("send() failed");
  else if (numBytes != echoStringLen)
    DieWithUserMessage("send()", "sent unexpected number of bytes");

  // Receive the same string back from the server
  unsigned int totalBytesRcvd = 0; // Count of total bytes received
  fputs("Received: ", stdout);     // Setup to print the echoed string
  while (totalBytesRcvd < echoStringLen) {
    char buffer[BUFSIZE]; // I/O buffer
    // Receive up to the buffer size (minus 1 to leave space for a null terminator) bytes from the sender
    // Use the "recv()" function, which returns the number of bytes received
    // start with "numBytes = recv(..."
    // [YOUR CODE HERE]
    
    if (numBytes < 0)
      DieWithSystemMessage("recv() failed");
    else if (numBytes == 0)
      DieWithUserMessage("recv()", "connection closed prematurely");
    
    totalBytesRcvd += numBytes; // Keep tally of total bytes
    buffer[numBytes] = '\0';    // Terminate the string!
    fputs(buffer, stdout);      // Print the buffer
  }

  fputc('\n', stdout); // Print a final linefeed

  close(sock);
  exit(0);
}