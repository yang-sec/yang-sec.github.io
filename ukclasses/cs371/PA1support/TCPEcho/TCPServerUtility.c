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

#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include "Practical.h"

void HandleTCPClient(int clntSocket) {
  char buffer[BUFSIZE]; // Buffer for echo string

  // Receive message from client
  // Use the "recv()" function, which returns the number of bytes received
  // start with "size_t numBytesRcvd = recv(..."
  // [YOUR CODE HERE]

  if (numBytesRcvd < 0)
    DieWithSystemMessage("recv() failed");

  // Send received string and receive again until end of stream
  while (numBytesRcvd > 0) { // 0 indicates end of stream
    // Echo message back to client
    // Use the "send()" function, which returns the number of bytes sent
    // start with "size_t numBytesSent = send(..."
    // [YOUR CODE HERE]

    if (numBytesSent < 0)
      DieWithSystemMessage("send() failed");
    else if (numBytesSent != numBytesRcvd)
      DieWithUserMessage("send()", "sent unexpected number of bytes");

    // See if there is more data to receive
    // [YOUR CODE HERE]
    if (numBytesRcvd < 0)
      DieWithSystemMessage("recv() failed");
  }

  // Close client socket
  // [YOUR CODE HERE]
}
