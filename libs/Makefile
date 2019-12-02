NAME_PlayerJojo	=	players/libPlayerJojo.so
# NAME_WeaponZeus	=	libWeaponZeus.so
# NAME_MapSky	=	libMapSky.so

SRC		=	src/PlayerJojo.cpp
# SRC2		=	src/WeaponZeus.cpp
# SRC3		=	src/MapSky.cpp

OBJ		=	$(SRC:.cpp=.o)
# OBJ2		=	$(SRC2:.cpp=.o)
# OBJ3		=	$(SRC3:.cpp=.o)

CC		=	g++

CPPFLAGS	=	-c -fPIC

all:	CompileAll

CompileAll:	$(OBJ) $(OBJ2) $(OBJ3)
	$(CC) -shared -o $(NAME_PlayerJojo) $(OBJ)
	# $(CC) -shared -o $(NAME_WeaponZeus) $(OBJ2)
	# $(CC) -shared -o $(NAME_MapSky) $(OBJ3)