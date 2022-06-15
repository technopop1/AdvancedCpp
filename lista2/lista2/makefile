# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : lista2.exe lista2.obj clean 
.PHONY : all

lista2.exe : lista2.obj
	link /DEBUG /OUT:lista2.exe lista2.obj

lista2.obj : lista2.cpp
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:lista2.obj lista2.cpp

#.PHONY: clean

clean :
	Del *.obj *.ilk *.pdb