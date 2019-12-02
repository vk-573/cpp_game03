NAME_PlayerJojo		=	players/libPlayerJojo.so
NAME_PlayerVince	=	players/libPlayerVince.so
NAME_PlayerDave		=	players/libPlayerDave.so
NAME_PlayerBab		=	players/libPlayerBab.so

NAME_WeaponSpeedy	=	weapons/libWeaponSpeedy.so
NAME_WeaponZeus		=	weapons/libWeaponZeus.so
NAME_WeaponSoldier	=	weapons/libWeaponSoldier.so
NAME_WeaponBazooka	=	weapons/libWeaponBazooka.so

# NAME_WeaponZeus	=	libWeaponZeus.so
# NAME_MapSky	=	libMapSky.so

SRC		=	src/PlayerJojo.cpp
SRC2		=	src/PlayerVince.cpp
SRC3		=	src/PlayerDave.cpp
SRC4		=	src/PlayerBab.cpp
SRC5		=	src/WeaponSpeedy.cpp
SRC6		=	src/WeaponZeus.cpp
SRC7		=	src/WeaponSoldier.cpp
SRC8		=	src/WeaponBazooka.cpp
# SRC3		=	src/MapSky.cpp

OBJ		=	$(SRC:.cpp=.o)
OBJ2		=	$(SRC2:.cpp=.o)
OBJ3		=	$(SRC3:.cpp=.o)
OBJ4		=	$(SRC4:.cpp=.o)
OBJ5		=	$(SRC5:.cpp=.o)
OBJ6		=	$(SRC6:.cpp=.o)
OBJ7		=	$(SRC7:.cpp=.o)
OBJ8		=	$(SRC8:.cpp=.o)


# OBJ2		=	$(SRC2:.cpp=.o)
# OBJ3		=	$(SRC3:.cpp=.o)

CC		=	g++

CPPFLAGS	=	-c -fPIC

all:	CompileAll

CompileAll:	$(OBJ) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8)
	$(CC) -shared -o $(NAME_PlayerJojo) $(OBJ)
	$(CC) -shared -o $(NAME_PlayerVince) $(OBJ2)
	$(CC) -shared -o $(NAME_PlayerDave) $(OBJ3)
	$(CC) -shared -o $(NAME_PlayerBab) $(OBJ4)
	$(CC) -shared -o $(NAME_WeaponSpeedy) $(OBJ5)
	$(CC) -shared -o $(NAME_WeaponZeus) $(OBJ6)
	$(CC) -shared -o $(NAME_WeaponSoldier) $(OBJ7)
	$(CC) -shared -o $(NAME_WeaponBazooka) $(OBJ8)

	# $(CC) -shared -o $(NAME_WeaponZeus) $(OBJ2)
	# $(CC) -shared -o $(NAME_MapSky) $(OBJ3)