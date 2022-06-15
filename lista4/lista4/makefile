# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : lista4.exe lista4.obj clean 
.PHONY : all

lista4.exe : lista4.obj
	link /DEBUG /OUT:lista4.exe lista4.obj

lista4.obj : lista4.cpp
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /openmp:experimental /Fo:lista4.obj lista4.cpp

clean :
	Del *.obj *.ilk *.pdb