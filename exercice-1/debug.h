//C macro to active debug printf
#ifdef DEBUG
#  define D(x) x
#else
#  define D(x) 
#endif