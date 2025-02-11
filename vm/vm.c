//
// Created by asxe on 2024/1/26.
//

#include "vm.h"
#include <stdlib.h>
#include "../utils/utils.h"
#include "core.h"

//初始化虚拟机
void initVM(VM *vm) {
    vm->allocatedBytes = 0;
    vm->allObjects = NULL;
    vm->curParser = NULL;
    StringBufferInit(&vm->allMethodNames);
    vm->allModules = newObjMap(vm);
}

VM *newVM(void) {
    VM *vm = (VM *) malloc(sizeof(VM));
    if (vm == NULL)
        MEM_ERROR("allocate VM memory failed.");
    initVM(vm);
    buildCore(vm);
    return vm;
}
