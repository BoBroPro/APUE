#include"apue.h"
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(void){
    int fd;
    char buf1[11] = "abcdefghij\0";
    char buf2[11] = "ABCDEFGHIJ\0";
    if((fd = open("file.hole", O_CREAT|O_RDWR, S_IRWXU)) < 0){
        err_sys("Creat error");
    }
    if(write(fd, buf1, 10) != 10){
        err_sys("buf1 write error");
    } // offset now is 10;
    if(lseek(fd,16384,SEEK_SET) == -1){
        err_sys("lseek error");
    }// offset now is 16384;
    if(write(fd, buf2, 10) < 0){
        err_sys("buf2 write error");
    }// offset new is 16394;
    exit(0);
}