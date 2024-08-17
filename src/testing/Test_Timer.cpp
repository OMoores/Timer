#include <gtest/gtest.h>
#include "timer.h"
#include <iostream>



int nullfunc() {
    std::cout << "Done thread stuff" << std::endl;

    return 0;
}


int main() {
    std::cout << "STARTED" << std::endl;
    SimpleTimer<int> simpt(500,&nullfunc);
}
// // Demonstrate some basic assertions.
// TEST(SimpleTimerTest, ConstructorTest) {
//     SimpleTimer simpt(500,&nullfunc);

//     EXPECT_EQ(7 * 6, 42);


// }

