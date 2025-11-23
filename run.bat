nasm -f win64 asmimgCvtGrayIntToDouble.asm
gcc -c cimgCvtGrayIntToDouble.c -o cimgCvtGrayIntToDouble.obj -m64
gcc cimgCvtGrayIntToDouble.obj asmimgCvtGrayIntToDouble.obj -o imgCvtGrayIntToDouble.exe -m64
imgCvtGrayIntToDouble.exe