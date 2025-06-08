cls

ARMIPS\bin\mips64-elf-gcc -Wall -O1 -mtune=vr4300 -march=vr4300 -mabi=32 -fomit-frame-pointer -G0 -c "CustomCode\Code.c" -o "CustomCode\Code.o"

ARMIPS\bin\armips "CustomCode\BUILD.asm"
ARMIPS\bin\n64crc "Rom\BM64_MOD.z64"
