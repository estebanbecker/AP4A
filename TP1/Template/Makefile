# differents types de fichiers 
.SUFFIXES:.o.cc.ln


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
FILES= Client.cc Vecteur.cc

#-----------
# LES CIBLES
#-----------

tp:  $(FILES:.cc=.o)
	$(CCC) -o tp $(FILES:.cc=.o) ${LIBS}

clean:
	/bin/rm $(FILES:.cc=.o) tp

#-----------------------------------------------------------------------------
# LES REGLES DE DEPENDANCE. Certaines sont implicites mais je recommande d'en 
# mettre une par fichier source. 
#-----------------------------------------------------------------------------

Client.o:Client.cc Vecteur.cc Vecteur.h
Vecteur.o:Vecteur.cc Vecteur.h

#---------------------------------
# REGLES DE COMPILATION IMPLICITES
#---------------------------------

.cc.o:; ${CCC} ${CCFLAGS} $*.cc

