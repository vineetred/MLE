#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <iostream>

#define MEM_ENV_VAR "MAXMEM_MB"
using namespace std;
void setmemlimit();

int main(int argc, char **argv)
{
        // launch MPI here first if you are doing so

        setmemlimit();

        // the rest of the program goes here
        // ...
        // ...
        cout<<"Hello World!";
        return 0;
}

void setmemlimit()
{
        struct rlimit memlimit;
        long bytes;

        if(getenv(MEM_ENV_VAR)!=NULL)
        {
                bytes = atol(getenv(MEM_ENV_VAR))*(1024*1024);
                memlimit.rlim_cur = bytes;
                memlimit.rlim_max = bytes;
                setrlimit(RLIMIT_AS, &memlimit);
        }
}