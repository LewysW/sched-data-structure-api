#include <cstdlib>

#include "api.h"
#include "../ThreadMap/threadMap.h"

#ifdef __cplusplus
extern "C" {
#endif

//Can define functions here which call C++, but must be callable from C

ThreadMap_s* createThreadMap() {
    return (ThreadMap_s*) new ThreadMap;
}


#ifdef __cplusplus
}
#endif
