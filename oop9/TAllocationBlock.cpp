#include "TAllocationBlock.h"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count): _size(size), _count(count) {
    _used_blocks = (char*) malloc(_size * _count);
    _free_blocks = new TStack<void*>();
    _used_blocks_all = new TStack<char*>();
    _used_blocks_all->Set(_used_blocks);
    for(size_t i = 0; i < _count; i++) {
        _free_blocks->Set(_used_blocks + i * _size);
    }
    // std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void* TAllocationBlock::allocate() {
    void *result = nullptr;
    if(!_free_blocks->Empty()) {
        result = _free_blocks->Get();
        // std::cout << "TAllocationBlock: Allocate " << std::endl;
    } else {
        // std::cout << "TAllocationBlock: Resize" << std::endl;

        _used_blocks = (char*) malloc(_size * _count);
        for(size_t i = 0; i < _count; i++) {
            _free_blocks->Set(_used_blocks + i * _size);
        }
        _used_blocks_all->Set(_used_blocks);
        _count *= 2;
        return TAllocationBlock::allocate();
    }
    return result;
}

void TAllocationBlock::deallocate(void *pointer) {
    // std::cout << "TAllocationBlock: Deallocate block "<< std::endl;
    _free_blocks->Set(pointer);
}

bool TAllocationBlock::has_free_blocks() {
    return _free_blocks->Size() > 0;
}

TAllocationBlock::~TAllocationBlock() {
    if(_free_blocks->Size() < _count) 
        std::cout << "TAllocationBlock: Memory leak?" << std::endl;
    else std::cout << "TAllocationBlock: Memory freed" << std::endl;
    delete _free_blocks;
    while (!_used_blocks_all->Empty()) {
        free(_used_blocks_all->Get());
    }
    delete _used_blocks_all;
}