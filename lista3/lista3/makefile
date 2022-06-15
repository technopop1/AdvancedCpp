# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : lista3.exe a.obj lista3.obj clean 
.PHONY : all

a.obj : a.cpp 
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:a.obj a.cpp

lista3.exe : lista3.obj a.obj
	link /DEBUG /OUT:lista3.exe lista3.obj a.obj

lista3.obj : lista3.cpp
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:lista3.obj lista3.cpp

#.PHONY: clean

clean :
	Del *.obj *.ilk *.pdb