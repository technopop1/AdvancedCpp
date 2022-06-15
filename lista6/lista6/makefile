# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : lista6.exe lista6.obj clean 
.PHONY : all

lista6.exe : lista6.obj
	link /DEBUG /OUT:lista6.exe lista6.obj

lista6.obj : lista6.cpp
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:lista6.obj lista6.cpp

clean :
	Del *.obj *.ilk *.pdb