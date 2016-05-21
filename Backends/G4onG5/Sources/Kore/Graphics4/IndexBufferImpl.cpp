#include "pch.h"
#include "IndexBufferImpl.h"
#include <Kore/Graphics4/Graphics.h>
#include <Kore/Graphics5/Graphics.h>
#include <assert.h>
#include <string.h>

using namespace Kore;
using namespace Kore::Graphics4;

IndexBuffer* IndexBufferImpl::current = nullptr;

IndexBufferImpl::IndexBufferImpl(int count) {
	buffer = new Graphics5::IndexBuffer(count);
}

IndexBuffer::IndexBuffer(int indexCount) : IndexBufferImpl(indexCount) {
	
}

IndexBuffer::~IndexBuffer() {
	
}

int* IndexBuffer::lock() {
	return buffer->lock();
}

void IndexBuffer::unlock() {
	buffer->unlock();
}

void IndexBuffer::_set() {
	current = this;
	buffer->_set();
}

void IndexBufferImpl::unset() {
	if ((void*)current == (void*)this) current = nullptr;
	buffer->unset();
}

int IndexBuffer::count() {
	return buffer->count();
}
