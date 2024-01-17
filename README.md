# C64 Mandelbrot

This is an implementation of the mandelbrot set plot in C64 BASIC V2 and C.

Be warned it takes hours to complete the hires plot in BASIC.

To compile the C version use cc65 with the following command line:
cl65 -C C64mod.cfg -O -o mandel.prg C64Mandelbrot.c

The prg file can then be loaded into an emulator (VICE using smart attach), or converted to a D64 file using the following command:
c1541 -format mandel,id d64 mandel.d64 -attach mandel.d64 -write mandel.prg
