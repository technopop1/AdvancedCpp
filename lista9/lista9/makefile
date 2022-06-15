# all wyznacza kolejność wykonywania poleceń przez .PHONY
all : Singleton.obj calls1.obj link.exe clean #lista9.obj 
.PHONY : all

link.exe : Singleton.obj calls1.obj
	link /LIB /OUT:static.lib Singleton.obj calls1.obj

#link.obj : lista9.cpp
#	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:lista9.obj lista9.cpp

Singleton.obj : Singleton.cpp 
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:Singleton.obj Singleton.cpp

calls1.obj : calls1.cpp 
	cl /std:c++20 /EHsc /c /Zi /W4 /WX /Fo:calls1.obj calls1.cpp


#.PHONY: clean

clean :
	Del *.obj *.ilk *.pdb