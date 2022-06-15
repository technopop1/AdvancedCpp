# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : lista5.exe lista5.obj clean 
.PHONY : all

lista5.exe : lista5.obj
	link /DEBUG /OUT:lista5.exe lista5.obj

lista5.obj : lista5.cpp
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:lista5.obj lista5.cpp

clean :
	Del *.obj *.ilk *.pdb