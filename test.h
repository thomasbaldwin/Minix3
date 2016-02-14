#define SUCCESS 0
#define FAILURE 1

#define PROMPT " > "
#define HELP "0 = exit; 1 = get <pid>; 2 = set <value>; 3 = set <current PID>"

#define MAX_PID 100

enum CMD { EXIT, GET, SET, SETPID };

int set_sv(int newval, int* status);
int get_sv(int pid, int* status);

void process_cmd(int command);

#ifdef TEST_IMPL
int curr_pid = 0; // used to allow user to check multiple values
int value[MAX_PID];  // automatically initiallized to 0's
#else
extern int curr_pid ;
extern int value[MAX_PID];  
#endif
