NAME_PlayerJojo		=	players/libPlayerJojo.so
NAME_PlayerVince	=	players/libPlayerVince.so
NAME_PlayerDave		=	players/libPlayerDave.so
NAME_PlayerBab		=	players/libPlayerBab.so

# NAME_WeaponZeus	=	libWeaponZeus.so
# NAME_MapSky	=	libMapSky.so

SRC		=	src/PlayerJojo.cpp
SRC2		=	src/PlayerVince.cpp
SRC3		=	src/PlayerDave.cpp
SRC4		=	src/PlayerBab.cpp
# SRC2		=	src/WeaponZeus.cpp
# SRC3		=	src/MapSky.cpp

OBJ		=	$(SRC:.cpp=.o)
OBJ2		=	$(SRC2:.cpp=.o)
OBJ3		=	$(SRC3:.cpp=.o)
OBJ4		=	$(SRC4:.cpp=.o)

# OBJ2		=	$(SRC2:.cpp=.o)
# OBJ3		=	$(SRC3:.cpp=.o)

CC		=	g++

CPPFLAGS	=	-c -fPIC

all:	CompileAll

CompileAll:	$(OBJ) $(OBJ2) $(OBJ3) $(OBJ4)
	$(CC) -shared -o $(NAME_PlayerJojo) $(OBJ)
	$(CC) -shared -o $(NAME_PlayerVince) $(OBJ2)
	$(CC) -shared -o $(NAME_PlayerDave) $(OBJ3)
	$(CC) -shared -o $(NAME_PlayerBab) $(OBJ4)
	# $(CC) -shared -o $(NAME_WeaponZeus) $(OBJ2)
	# $(CC) -shared -o $(NAME_MapSky) $(OBJ3)