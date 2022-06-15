# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : lista7.exe a.obj lista7.obj clean 
.PHONY : all

a.obj : a.cpp 
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:a.obj a.cpp

lista7.exe : lista7.obj a.obj
	link /DEBUG /OUT:lista7.exe lista7.obj a.obj

lista7.obj : lista7.cpp
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:lista7.obj lista7.cpp

#.PHONY: clean

clean :
	Del *.obj *.ilk *.pdb