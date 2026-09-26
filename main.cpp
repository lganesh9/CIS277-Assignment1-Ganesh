#include <iostream>
#include <vector>
#include "MemoryPool.h"

using namespace std;

int main()
{
    unsigned char packet[] = {
        0x45, 0x00, 0x00, 0x3C,
        0xAB, 0xCD, 0x12, 0x34};
    void *blocks[9];
    MemoryPool pool(512, 8);
    cout << "The size of each block is " << pool.blockSize() << ", there are " << pool.availableBlocks() << " blocks, and the total pool capacity is " << pool.capacity() << endl;

    blocks[1] = pool.allocate();
    if (blocks[1] == nullptr)
    {
        cout << "allocate() returned nullptr\n";
    }
    cout << "Packet 1 allocated: " << blocks[1] << endl;

    blocks[2] = pool.allocate();
    if (blocks[2] == nullptr)
    {
        cout << "allocate() returned nullptr\n";
    }
    cout << "Packet 2 allocated: " << blocks[2] << endl;

    blocks[3] = pool.allocate();
    if (blocks[3] == nullptr)
    {
        cout << "allocate() returned nullptr\n";
    }
    cout << "Packet 3 allocated: " << blocks[3] << endl;

    cout << "Available Blocks: " << pool.availableBlocks() << endl;
    cout << "Allocated Blocks: " << pool.allocatedBlocks() << endl;

    memcpy(blocks[1], packet, sizeof(packet));
    cout << "Binary packet written to packet 1\n";

    for (int i = 0; i < 8; i++)
        cout << hex << static_cast<int>(packet[i]) << " ";

    unsigned char readback[8];
    memcpy(readback, blocks[1], sizeof(packet));

    cout << "\nRead: ";
    for (int i = 0; i < 8; i++)
        cout << hex << static_cast<int>(readback[i]) << " ";

    pool.deallocate(blocks[2]);
    cout << "\nReleased Packet 2\n";
    cout << "Available Blocks: " << pool.availableBlocks() << endl;
    cout << "Allocated Blocks: " << pool.allocatedBlocks() << endl;

    blocks[4] = pool.allocate();
    if (blocks[4] == nullptr)
    {
        cout << "allocate() returned " << blocks[4] << endl;
    }
    cout << "Packet 4 allocated: " << blocks[4] << endl;

    blocks[2] = pool.allocate();
    if (blocks[2] == nullptr)
    {
        cout << "allocate() returned " << blocks[2] << endl;
    }

    for (int i = 4; i < 9; i++)
    {
        blocks[i] = pool.allocate();
        if (blocks[i] == nullptr)
        {
            cout << "allocate() returned " << blocks[i] << endl;
        }
    }

    bool chk = pool.deallocate(blocks[4]);
    cout << "The first deallocation returned " << (chk ? "Success" : "Rejected") << endl;
    chk = pool.deallocate(blocks[4]);
    cout << "The second deallocation returned " << (chk ? "Success" : "Rejected") << endl;
    return 0;
}