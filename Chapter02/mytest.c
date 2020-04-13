#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
int test_OPEN_MAX(void);
int main(){
    
}
int test_OPEN_MAX(void){
    long val = 0;
    if((val = sysconf(_SC_OPEN_MAX)) < 0){
        if(errno == EINVAL){
            printf("the SC_FILE_MAX is not defined\n");
        }
        else{
            printf("unknown error\n");
        }
    }
    else{
        printf("the value of _SC_OPEN_MAX is %d\n", val);
    }
    return 0;
}
