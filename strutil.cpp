#include "strutil.h"

#include <cstdlib>

namespace pr {


// version index
size_t length2 (const char *str) {
	size_t ret = 0;
	for (int i=0 ; str[i] ; ++i) {
		++ret;
	}
	return ret;
}

// version pointeurs
size_t length (const char *str) {
	size_t ret = 0;
	for ( ; *str ; ++str) {
		++ret;
	}
	return ret;
}


// version index
char * newcopy2 (const char *src) {
	size_t n = length(src);
	char * dest = new char[n+1];

	// avec <= pour attraper le dernier '\0'
	for (size_t i=0; i <= n ; ++i) {
		dest[i] = src[i];
	}

	return dest;
}

// version index + malloc
char * newcopy4 (const char *src) {
	size_t n = length(src);
	// void * malloc (size_t sz)
	// pour allouer un tableau, multiplier la taille (sizeof) par le nombre de cellules
	// la signature force un cast pour remonter de void * vers le vrai type voulu
	char * dest = (char *) malloc( (n+1)*sizeof(char) );

	// avec <= pour attraper le dernier '\0'
	for (size_t i=0; i <= n ; ++i) {
		dest[i] = src[i];
	}

	return dest;
}

// une version pointeurs
// il y a beaucoup de variantes.
char * newcopy3 (const char *src) {
	size_t n = length(src);
	char * dest = new char[n+1];

	char *cd=dest ;
	while (true) {
		*cd = *src;
		if (! *src) {
			break;
		}
		++cd;
		++src;
	}
	return dest;
}

// version memcpy
// *toujours* la version à recommander en production
// habite dans #include <cstring>
char * newcopy (const char *src) {
	size_t n = length(src);
	char * dest = new char[n+1];

	// dest, source, nombre de bytes = n+1 avec le \0
	memcpy(dest,src,n+1);

	return dest;
}

}

