#ifndef P00_PRAGMAS_H_
#define P00_PRAGMAS_H_

#define P01_PRAGMA_(STR) _Pragma(STR)
#define P01_PRAGMA(...) P01_PRAGMA_(#__VA_ARGS__)
#define P44_PRAGMA(...) P01_PRAGMA(__VA_ARGS__)

#ifdef __GNUC__
#  ifdef __clang__
#    define P01_CLANG_DIAGNOSTIC_IGNORED(diag) \
        P99_PRAGMA(clang diagnostic push)    \
        P99_PRAGMA(clang diagnostic ignored #diag)
#    define P01_CLANG_POP() _Pragma("clang diagnostic pop")
#    define P01_GCC_DIAGNOSTIC_IGNORED(diag)
#    define P01_GCC_POP()
#  else
#    define P01_CLANG_DIAGNOSTIC_IGNORED(diag)
#    define P01_CLANG_POP()
#    define P01_GCC_DIAGNOSTIC_IGNORED(diag) \
        P99_PRAGMA(GCC diagnostic push)    \
        P99_PRAGMA(GCC diagnostic ignored #diag)
#    define P01_GCC_POP() _Pragma("GCC diagnostic pop")
#  endif

#  define P01_GCC_IGNORE_UNKNOWN_PRAGMAS() \
        P01_GCC_DIAGNOSTIC_IGNORED(-Wunknown-pragmas)

#  define P01_CLANG_IGNORE_DISCARDED_QUALS() \
        P01_CLANG_DIAGNOSTIC_IGNORED(-Wincompatible-pointer-types-discards-qualifiers)


#  define P01_POP_BOTH()  P01_CLANG_POP()  P01_GCC_POP()
#  define P01_POP_CLANG_GCC()  P01_CLANG_POP()  P01_GCC_POP()
#else
#  define P01_GCC_DIAGNOSTIC_IGNORED(diag)
#  define P01_CLANG_DIAGNOSTIC_IGNORED(diag)
#  define P01_GCC_IGNORE_UNKNOWN_PRAGMAS()
#  define P01_CLANG_IGNORE_DISCARDED_QUALS()
#  define P01_GCC_POP()
#  define P01_CLANG_POP()
#  define P01_POP_BOTH()
#endif

#endif
