# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : zbiornikpaliwa.obj silnik.obj lista8.obj  lista8.exe clean 
.PHONY : all

lista8.exe : lista8.obj Silnik.obj
	link /DEBUG /OUT:lista8.exe lista8.obj zbiornikpaliwa.obj silnik.obj

lista8.obj : lista8.cpp
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:lista8.obj lista8.cpp

silnik.obj : silnik.cpp 
	cl /std:c++20 /EHsc  /c /Zi /W4 /WX /Fo:silnik.obj silnik.cpp

zbiornikpaliwa.obj : zbiornikpaliwa.cpp 
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:zbiornikpaliwa.obj zbiornikpaliwa.cpp

#.PHONY: clean

clean :
	Del *.obj *.ilk *.pdb