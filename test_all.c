#include <stdio.h>

#define SUCCESS 0
#define FAILURE 1

#define PROMPT " > "
#define HELP "0 = exit; 1 = get <pid>; 2 = set <value>; 3 = set <current PID>"

#define MAX_PID 100

enum CMD { EXIT, GET, SET, SETPID };

int curr_pid = 0; // used to allow user to check multiple values
int value[MAX_PID];  // automatically initiallized to 0's

int set_sv(int newval, int* status) 
{
	*status = SUCCESS;
	value[curr_pid] = newval;
	return value[curr_pid];
}

int get_sv(int pid, int* status)
{
        if ((pid < 0) || (pid >= MAX_PID))
        {
                *status = FAILURE;
                return (0);
        }
        else
        {
                *status = SUCCESS;
                return value[pid];
        }
}

void process_cmd(int command)
{
  int input, stat;

  switch (command) 
  {
    case GET:
	printf("Get\n");
	printf("PID = ");
        if (scanf("%d", &input) == 1) 
	{
          if ((input < 0) || (input >= MAX_PID))
          {
	    fprintf(stderr, "Invalid PID: %d. ", input);
	    fprintf(stderr, "Must positive and < %d\n", MAX_PID);
          }
          else
          {
	    printf("Current value = %d\n", get_sv(input, &stat));
          }
	}
	else
	{
	  fprintf(stderr, "Bad input - PID must be an integer\n");
	}
	break;
    case SET:
	printf("Set\n");
	printf("New value = ");
        if (scanf("%d", &input) == 1) 
	{
	  printf("Current value = %d\n", set_sv(input, &stat));
	}
	else
	{
	  fprintf(stderr, "Bad input - new value must be an integer\n");
	}
	break;
    case SETPID:
	printf("SetPID\n");
	printf("New current PID = ");
        if (scanf("%d", &input) == 1) 
	{
          if ((input < 0) || (input >= MAX_PID))
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

main()
{
  int cmd = GET;

  while (cmd != EXIT)
  {
    printf(PROMPT);
    if (scanf("%d", &cmd) == 1) 
    {
      process_cmd(cmd);
    } // if-then
    else
    {
      fprintf(stderr, "Bad input - bye\n");
      cmd = EXIT;
    } // if-else
  } // while
}
