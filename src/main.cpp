
// ===== Phase 1: Basic ownership ===== 1/22
// ===== Phase 2: Deep copy ===== 1/22
// ===== Phase 3: Move semantics ===== 1/23
// ===== Phase 4: Assignment operators ===== 1/23
// ===== Phase 5: RVO experiment ===== 1/23
// ===== Phase 6: logger module added ===== 1/24
// ===== Phase 7: record module added ===== 1/24
// ===== Phase 8: Device.h file added ===== 1/25
// ===== Phase 9: FakeDevice module added ===== 1/25

#include <iostream>
#include "logger.h"
#include "record.h"
#include "FakeDevice.h"
//#include "buffer.h"

using namespace std;

int main(){
    //cout << "Entering main()\n";

    Logger logger("log.txt");

    FakeDevice devA("SensorA", 10, 42);
    FakeDevice devB("SensorB", 5, 7);

    logger.write(devA.read());
    logger.write(devB.read());

    //cout << "\nExiting main()\n";
    return 0;
}


