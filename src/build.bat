nasm -f elf64 -o start.o start.asm
ld -T link.ld -o kernel.bin start.o
