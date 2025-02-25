#include <windows.h>
#include <stdio.h>

void print_memory_usage() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    
    printf("\033[H\033[J");
    printf("Memory Usage Monitor:\n");
    printf("Total Physical Memory: %llu MB\n", memInfo.ullTotalPhys / (1024 * 1024));
    printf("Available Physical Memory: %llu MB\n", memInfo.ullAvailPhys / (1024 * 1024));
    printf("Memory Load: %lu%%\n", memInfo.dwMemoryLoad);
}

int main() {
    while (1) {
        print_memory_usage();
        Sleep(1000);
    }
    return 0;
}

