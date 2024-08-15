#include <gtest/gtest.h>
#include "timer.h"
#include <iostream>



void nullfunc() {
    std::cout << "Done thread stuff" << std::endl;
}


int main() {
    std::cout << "STARTED" << std::endl;
    SimpleTimer simpt(500,&nullfunc);
}
// // Demonstrate some basic assertions.
// TEST(SimpleTimerTest, ConstructorTest) {
//     SimpleTimer simpt(500,&nullfunc);

//     EXPECT_EQ(7 * 6, 42);


// }

