# Touch Sensing on MKL05Zx4 with Freescale/NXP TSS library.

## Important
For the library to build, the build configuration must have the following
settings:
1. Include TSS_KXX_M0 in C/C++ Build / Tool Settings / Cross ARM C++ Linker / Libraries
1. Language Standard should be "Toolchain Default (GNU ISO C90)" in
 C/C++ Build / Tool Settings / Cross ARM C Compiler / Optimization.
 
 For more details see: https://community.nxp.com/thread/390760

## Touch Sensing Library
This code uses the Freescale touch sensing library provided by
Freescale Processor Expert.

Search "TSSUG" for Touch Sensing Users Guide and
"TSSAPIRM" for reference material.
