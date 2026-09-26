# CIS-277 Assignment 1: Network Packet Buffer Pool

## Student
Logan Ganesh

## Description

## Stack Implementation
I chose to use a vector purely because it was easier to implement. I would like to try to use a dynamic array, however that is for the future.

## How to Compile
cmd /c chcp 65001>nul && cl.exe /Zi /EHsc /nologo /FeC:\Users\lsgan\OneDrive\Documents\Things\Code\Projects\c++\main.exe C:\Users\lsgan\OneDrive\Documents\Things\Code\Projects\c++\main.cpp C:\Users\lsgan\OneDrive\Documents\Things\Code\Projects\c++\MemoryPool.cpp


## Analysis Questions
1. Why is a Stack appropriate for managing the free blocks in this memory pool?
It is appropriate because it all of the blcoks are the same size, and it is efficient since it keeps an O(1) time complexity. The method to access the stack itself and to make changes are all simple and there is no need for loops.
2. What happens when the free-block Stack becomes empty?
When it became empty, either the method empty() can be used or it would get returned nullptr.
3. Why must a released block be returned to the Stack?
It must be returned because otherwise the stack permanently shrinks as the block would never be able to be handed out again.
4. What problem could occur if the same block were deallocated twice?
It would return the same address twice. Then the next two allocate() would lead to the same address having two different owners. This would corrupt the data that was being stored by the owners. 
5. What is the Big-O time complexity of allocate()? Explain why.
It is O(1). This is because there are no loops that are being used to allocate the blocks. The only things that are being done is checking whether the stack is empty, some math to find the correct index, and the pop() method.
6. What is the Big-O time complexity of deallocate()? Explain why.
deallocate would be O(1) as well. The only things that are done in this method is simple math, a read/write, and the push() method.