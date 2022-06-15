# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : lista1.exe lista1.obj clean 
.PHONY : all

lista1.exe : lista1.obj
	link /DEBUG /OUT:lista1.exe lista1.obj

lista1.obj : lista1.cpp wektor.h
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:lista1.obj lista1.cpp

#.PHONY: clean

clean :
	Del *.obj *.ilk *.pdb