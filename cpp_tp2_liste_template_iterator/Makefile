# differents types de fichiers 
.SUFFIXES:.o.cpp.ln


#---------------------------------
# INITIALISATION DES VARIABLES 
#---------------------------------

# Indiquer le compilateur
CCC = g++

# Les chemins ou se trouvent les fichiers a inclure
INCLUDES= -I/usr/openwin/include

# Options de compilation.
CCFLAGS=  ${INCLUDES} -c

# Options pour le linker.
LFLAGS=  -o 

# Les librairies avec lesquelle on va effectueller l'edition de liens
LIBS=

# Les fichiers sources de l'application
FILES= main.cpp ListeRecursif.h

#-----------
# LES CIBLES
#-----------

tp:  $(FILES:.cc=.o)
	$(CCC) -o tp $(FILES:.cc=.o) ${LIBS} -g

clean:
	/bin/rm $(FILES:.cc=.o) tp

#-----------------------------------------------------------------------------
# LES REGLES DE DEPENDANCE. Certaines sont implicites mais je recommande d'en 
# mettre une par fichier source. 
#-----------------------------------------------------------------------------

main.o:main.cpp ListeRecursif.h
ListeRecursif.o:ListeRecursif.h

#---------------------------------
# REGLES DE COMPILATION IMPLICITES
#---------------------------------

.cc.o:; ${CCC} ${CCFLAGS} $*.cc

