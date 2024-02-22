#include <iostream>
#include <windows.h>

void printMemoryInfo() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);

    DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
    DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

    std::cout << "Total Memory: " << totalPhysMem / (1024 * 1024) << " MB\n";
    std::cout << "Used Memory: " << physMemUsed / (1024 * 1024) << " MB\n";
}

int main() {
    std::cout << "System Memory Information:\n";
    printMemoryInfo();
    return 0;
}
