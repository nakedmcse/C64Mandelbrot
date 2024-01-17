ca65 -t c64 float.s -o float.o
cc65 floatc.c -o floatc.s
ca65 floatc.s -o floatc.o
ar65 a runtime.lib float.o floatc.o