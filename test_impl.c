/* test_impl.c
   By: R. Newman
   Creation: 2/9/16

   Test harness procedures to test get_sv() and set_sv() library procedures.
   The test_main.c program was linked with fake get_sv and set_sv procedures 
   to allow it to be tested. 
   Students must link the test_main.c and test_impl.c code with their 
   get_sv and set_sv routines to demonstrate their changes. 
   Two processes running test can show the value of the other process's
   shared variable, and can change the value of their own.
   Changes to test.h may be required. 
 */
#include <stdio.h>
#define TEST_IMPL
#include "test.h"

void process_cmd(int command)
{
  int input, stat;

  switch (command) 
  {
    case GET:
	printf("Get\n");
	printf("PID = ");
        if (scanf("%d", &input) == 1) // scanned an int
	{	// should test for valid PID
		// should test for status before printing
	  printf("Current value = %d\n", get_sv(input, &stat));
	}
	else	// did not scan an int
	{
	  fprintf(stderr, "Bad input - PID must be an integer\n");
	}
	break;
    case SET:
	printf("Set\n");
	printf("New value = ");
        if (scanf("%d", &input) == 1) // scanned an int
	{	// this should change own process' sv
	  printf("Current value = %d\n", set_sv(input, &stat));
	}
	else	// did not scan an int
	{
	  fprintf(stderr, "Bad input - new value must be an integer\n");
	}
	break;
    case SETPID:	// this is really only needed to test stubs
			// so that set_sv can be tested for this harness
	printf("SetPID\n");
	printf("New current PID = ");
        if (scanf("%d", &input) == 1) 
	{
          if ((input < 0) || (input >= MAX_PID))	// only for this pgm
          {
            fprintf(stderr, "Invalid PID: %d. ", input);
            fprintf(stderr, "Must positive and < %d\n", MAX_PID);
          }
          else
          {
	  	curr_pid = input;
          }
  	  printf("Current PID = %d\n", curr_pid);
	}
	else
	{
	  fprintf(stderr, "Bad input - new value must be an integer\n");
	}
	break;
    case EXIT:
	printf("Exit\n");
	break;
    default:
	printf("Unrecognized command: %d\n", command);
	printf("%s\n", HELP);
  }
}
