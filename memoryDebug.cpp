// #pragma once
// #include <iostream>
// using namespace std;

// struct AllocationMetrics{
//     int TotalAllocated = 0;
//     int TotalFreed = 0;
//     int CurrentUsage() { 
//         return TotalAllocated - TotalFreed; 
//     }
// };

// static AllocationMetrics s_allocationMetrics;

// void* operator new(size_t size){
//     s_allocationMetrics.TotalAllocated += size;
//     //cout << "Allocating " << size << " bytes" << endl;
//     return malloc(size);
// }

// void operator delete(void* memory, size_t size){
//     s_allocationMetrics.TotalFreed += size;
//     cout << "Freeing " << size << " bytes" << endl;
//     free(memory);
// }

// static void PrintMemoryUsage(){
//     cout << "Memory Usage: " << s_allocationMetrics.CurrentUsage() << " bytes" << endl;
// }
