#include <iostream>
using namespace std;

enum CPU_Rank {
        P1 = 1,
        P2,
        P3,
        P4,
        P5,
        P6,
        P7
};
class CPU {
public:
    CPU () {}
    CPU (int fre, float vol) : frequency(fre), voltage(vol) {
        cout << "1" <<endl;
    }
    ~CPU () {
        cout << "class is destoryed" << endl;
    }
    void run() {};
    void stop() {};
    void show () {
        cout << "CPU_show" << endl;
        cout << frequency << ' ' << voltage << endl;
    }
private:
    int frequency;
    float voltage;
    int rank;
};
class RAM {
public:
    RAM (){}
    ~RAM(){}
    void show () {
        cout << "RAM_show" << endl;
    }
};
class CDROM {
public:
    CDROM () {}
    ~CDROM() {}
    void show () {
        cout << "CDROM_show" << endl;
    }
};

class Computer {
public:
    Computer () {}
    Computer (const CPU &cpu, const RAM &ram, const CDROM &cdrom) : cpu (cpu), ram(ram), cdrom(cdrom) {}
    ~Computer () {}
    void run () {
        cpu.show();
        ram.show();
        cdrom.show();
    }
    void stop () {}
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};
int main () 
{
    CPU cpu1 = CPU(114, 5.14);
    RAM ram1;
    CDROM cdrom1;2awq
    Computer com =  Computer(cpu1, ram1, cdrom1);
    com.run();
}
