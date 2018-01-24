@echo off
call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Auxiliary\\Build\\vcvarsall.bat" x64     
c:
cd %~dp0
del -y main.exe main.ilk main.obj main.pdb vc140.pdb

set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:main.exe
cl.exe %compilerflags% main.cpp /link %linkerflags%

echo "-------start testing-------"
main.exe
echo "--------done----------------"