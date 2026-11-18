#include <stdio.h>
#include "crador.h"
#include <math.h>


int creador(int *lenght, int *attemp, char *password)
{
	
	//Defining the lenght of the password because I want it to be limitless in terms of the size of the password.
  //	char password[*lenght + 1];
  int final;
  int position;
  char caracter;
  for (int i; i<sizeof(password); i++){
    password[i] = password[i]+33;
  }

	for (int i = 0; i < *lenght; i++)
	{
    final = *attemp/94;
    /* The stuff down there goes here */
    
    char final_converted[20];
    snprintf(final_converted, sizeof final_converted, "%d", final);
    printf("Second %c\n", final_converted[0]); //Debugging

    for (int i=0; i < *lenght-1; i++) {
      printf("%i\tAntes %c\n", i, final_converted[i]); //Debugging
      password[i] = password[i]+final_converted[i];
      printf("%i\tDepués %c\n", i, final_converted[i]); //Debugging
    }
  }
	//Printing for debugging and adding '\0' to password at the end to make it a valid string
	password[*lenght] = '\0';
	printf("%s\n", password);
	return 0;
}


    /*
    caracter = *attemp + 33;
    if (final < 1.0){
      position = *lenght - *lenght;
    } else if (final < 2 && final > 1) {
      position = *lenght - *lenght + round(final);

    }
    password[position] = (char)position;

    /*
		//Adding characters to password
		int position = *attemp + i + 33; //We add +33 to the attemp so it's inside the ascii table.
		(*password)[i] = (char)position; // Convert position to a character so we can  add it to password
	  */
