all: python



python.o: python.asm
	nasm -f elf32 -o python.o python.asm
python: python.o
	ld -e _main -melf_i386 -o python python.o 
	touch sahid.txt
clean:
	rm -f *.o
	rm python
	rm -f *.txt
