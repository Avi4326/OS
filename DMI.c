#include <stdlib.h>
#include <stdio.h>

int main() {

    printf("---- Linux Kernel Memory Information ----\n\n");

    // Total, Used, Free memory
    printf(">> Basic Memory Info (free -h)\n");
    system("free -h");

    // Kernel-level configured memory (filtered)
    printf("\n>> Kernel Configured Memory (/proc/meminfo)\n");
    system("grep -E \"MemTotal|MemFree|MemAvailable|Buffers|Cached\" /proc/meminfo");

    return 0;
}
