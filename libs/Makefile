#players
NAME_PlayerJojo		=	players/libPlayerJojo.so
NAME_PlayerVince	=	players/libPlayerVince.so
NAME_PlayerDave		=	players/libPlayerDave.so
NAME_PlayerBab		=	players/libPlayerBab.so

#weapons
NAME_WeaponSpeedy	=	weapons/libWeaponSpeedy.so
NAME_WeaponZeus		=	weapons/libWeaponZeus.so
NAME_WeaponSoldier	=	weapons/libWeaponSoldier.so
NAME_WeaponBazooka	=	weapons/libWeaponBazooka.so

#maps
NAME_MapCave		=	maps/libMapCave.so
NAME_MapSpace		=	maps/libMapSpace.so

SRC		=	src/PlayerJojo.cpp
SRC2		=	src/PlayerVince.cpp
SRC3		=	src/PlayerDave.cpp
SRC4		=	src/PlayerBab.cpp
SRC5		=	src/WeaponSpeedy.cpp
SRC6		=	src/WeaponZeus.cpp
SRC7		=	src/WeaponSoldier.cpp
SRC8		=	src/WeaponBazooka.cpp
SRC9		=	src/MapCave.cpp
SRC10		=	src/MapSpace.cpp

OBJ		=	$(SRC:.cpp=.o)
OBJ2		=	$(SRC2:.cpp=.o)
OBJ3		=	$(SRC3:.cpp=.o)
OBJ4		=	$(SRC4:.cpp=.o)
OBJ5		=	$(SRC5:.cpp=.o)
OBJ6		=	$(SRC6:.cpp=.o)
OBJ7		=	$(SRC7:.cpp=.o)
OBJ8		=	$(SRC8:.cpp=.o)
OBJ9		=	$(SRC9:.cpp=.o)
OBJ10		=	$(SRC10:.cpp=.o)

CC		=	g++

CPPFLAGS	=	-c -fPIC

all:	CompileAll

CompileAll:	$(OBJ) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10)
	$(CC) -shared -o $(NAME_PlayerJojo) $(OBJ)
	$(CC) -shared -o $(NAME_PlayerVince) $(OBJ2)
	$(CC) -shared -o $(NAME_PlayerDave) $(OBJ3)
	$(CC) -shared -o $(NAME_PlayerBab) $(OBJ4)
	$(CC) -shared -o $(NAME_WeaponSpeedy) $(OBJ5)
	$(CC) -shared -o $(NAME_WeaponZeus) $(OBJ6)
	$(CC) -shared -o $(NAME_WeaponSoldier) $(OBJ7)
	$(CC) -shared -o $(NAME_WeaponBazooka) $(OBJ8)
	$(CC) -shared -o $(NAME_MapCave) $(OBJ9)
	$(CC) -shared -o $(NAME_MapSpace) $(OBJ10)