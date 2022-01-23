all : fontsize fontsize_ogl

#for X11 consider:             xorg-dev
#for X11, you will need:       libx-dev
#for full screen you'll need:  libxinerama-dev libxext-dev
#for OGL You'll need:          mesa-common-dev libglu1-mesa-dev

#-DCNFGRASTERIZER
#  and
#-CNFGOGL
#  are incompatible.

# gcc -o $@ $^ -lX11 -lm -lpthread -lXinerama -lXext -lGL -g -DCNFGRASTERIZER -Wall -L/rawdraw_sf.h

MINGW32:=/usr/bin/i686-w64-mingw32-
SRC=src/*

main : src/main.cc
	g++ -o $@ $^ -lX11 -L/src/lib/rawdraw_sf.h

# main_ogl : src/main.cc src/*
# 	g++ -o $@ $^ -lX11 -lm -lpthread -lXinerama -lXext -lGL -g -lX11 -lXinerama -lGL -DCNFGOGL -Wall

# main.exe : src/main.cc src/*
# 	$(MINGW32)g++ -m32 -o $@ $^  -lgdi32 $(CFLAGS)

# clean :
# 	rm -rf *.o *~ rawdraw.exe rawdraw ontop rawdraw_mac rawdraw_mac_soft rawdraw_mac_cg rawdraw_mac_ogl ogltest ogltest.exe rawdraw_egl main main_ogl main.exe
