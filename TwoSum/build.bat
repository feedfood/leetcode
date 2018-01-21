@echo off
call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Auxiliary\\Build\\vcvarsall.bat" x64     
f:
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:TwoSum.exe
cl.exe %compilerflags% TwoSum.cpp /link %linkerflags%

TwoSum.exe