#ifndef P00_PRAGMAS_H_
#define P00_PRAGMAS_H_

#ifdef __GNUC__
# define P01_GCC_IGNORE_UNKNOWN_PRAGMAS() \
        _Pragma("GCC diagnostic push")    \
        _Pragma("GCC diagnostic ignored \"-Wunknown-pragmas\"")

# define P01_CLANG_IGNORE_DISCARDED_QUALS() \
        _Pragma("clang diagnostic push")    \
        _Pragma("clang diagnostic ignored \"-Wincompatible-pointer-types-discards-qualifiers\"")

# define P01_GCC_POP()   _Pragma("GCC diagnostic pop")
# define P01_CLANG_POP() _Pragma("clang diagnostic pop")
# define P01_POP_BOTH()  P01_CLANG_POP()  P01_GCC_POP()
#else
# define P01_GCC_IGNORE_UNKNOWN_PRAGMAS()
# define P01_CLANG_IGNORE_DISCARDED_QUALS()
# define P01_GCC_POP()
# define P01_CLANG_POP()
# define P01_POP_BOTH()
#endif

#endif
