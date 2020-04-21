#ifdef __cplusplus
extern "C" {
#endif

// LocateCom locates COM ports that have "name" (case sensitive) as part of their friendly name
// Two behaviours:
// (a) If "list" is NULL and/or maxnum is <=0, the first matching port number is returned
//     as the function return value (1 to 255). If no port is found, the function returns 0.
// (b) If "list" is non-null and maxnum is >0, then the function returns up to maxnum
//     matching port numbers in the list array. The function return value is then
//     the number of matching ports found.
//
// NOTE that setting name to "" will return ALL com port numbers currently present.

int LocateCom(char *name, int *list, int maxnum);

#ifdef __cplusplus
}
#endif
