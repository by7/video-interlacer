#!/bin/bash
#simple sanity check

rm -f tests.out
./GenerateTests
./Interlacing test1_0.avi test1_1.avi >> tests.out
./Interlacing test2_0.avi test2_1.avi >> tests.out
./Interlacing test3_0.avi test3_1.avi >> tests.out
./Interlacing test4_0.avi test4_1.avi >> tests.out
./Interlacing test5_0.avi test5_1.avi >> tests.out
./Interlacing test6_0.avi test6_1.avi >> tests.out
diff tests.out expected.out
