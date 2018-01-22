@echo off
call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Auxiliary\\Build\\vcvarsall.bat" x64     
c:
cd %USERPROFILE%/source/repos/leetcode/AddTwoNumbers
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:AddTwoNumbers.exe
cl.exe %compilerflags% AddTwoNumbers.cpp /link %linkerflags%

AddTwoNumbers.exe