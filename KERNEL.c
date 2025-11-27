#include <stdlib.h>
#include <stdio.h>

int main() {

    printf("---- Kernel Information ----\n");
    system("uname -a");           // full kernel details

    printf("\n---- Kernel Version ----\n");
    system("uname -r");           // release version only

    printf("\n---- CPU Details (lscpu) ----\n");
    system("lscpu");              // CPU architecture + model

    printf("\n---- CPU Info (/proc/cpuinfo) ----\n");
    system("cat /proc/cpuinfo");  // detailed CPU hardware info

    return 0;
}