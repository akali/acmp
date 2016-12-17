#include <iostream>
using namespace std;
inline unsigned DiskNumber(unsigned i)
{
    unsigned disk_number = 1;
    while(!(i & 1))
    {
        i >>= 1;
        ++disk_number;
    }
    return disk_number;
}
inline unsigned Shifts(unsigned i, unsigned disk_number)
{
    return (i >> disk_number) + 1;
}
inline unsigned Delta(unsigned disks, unsigned disk_number)
{
    unsigned odd = disks & 1;
    return 2 - (odd ^ (disk_number & 1));
}

inline unsigned Src(unsigned shifts, unsigned delta)
{
    return (delta * (shifts - 1)) % 3;
}

inline unsigned Rec(unsigned shifts, unsigned delta)
{
    return (delta * shifts) % 3;
}

inline void out(unsigned count, unsigned src, unsigned rec)
{
    cout << DiskNumber(count)<< " "
         << src +1<<" "<< rec +1
         << endl;
}
void hanoy(unsigned disks)
{
    unsigned steps = (1 << (disks)) - 1;

    for(unsigned i = 1; i <= steps; i++)
    {
        unsigned disk_number = DiskNumber(i);
        unsigned shifts = Shifts(i, disk_number);
        unsigned delta = Delta(disks, disk_number);
        out(i, Src(shifts, delta), Rec(shifts, delta));
    }

    /*cout << endl << "Used " << disks << " disks. "
         << endl << "Make " << steps << " steps."
         << endl;*/
}

int main()
{
    unsigned disks;
    cin >> disks;
    //cout << "Hanoy with " << disks <<" disks:" << endl;
    hanoy(disks);
return 0;
}

