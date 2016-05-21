#include "pch.h"
#include "VertexBufferImpl.h"
#include "ShaderImpl.h"
#include <Kore/Graphics4/Graphics.h>
#include <Kore/Graphics5/Graphics.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

using namespace Kore;
using namespace Kore::Graphics4;

namespace {
	const int multiple = 100;
}

VertexBufferImpl::VertexBufferImpl(int count, const VertexStructure& structure, int instanceDataStepRate) {
	buffer = new Graphics5::VertexBuffer(count, structure, instanceDataStepRate);
}

VertexBuffer::VertexBuffer(int vertexCount, const VertexStructure& structure, int instanceDataStepRate) : VertexBufferImpl(vertexCount, structure, instanceDataStepRate) {
	
}

VertexBuffer::~VertexBuffer() {
	unset();
	delete buffer;
}

float* VertexBuffer::lock() {
	return buffer->lock();
}

void VertexBuffer::unlock() {
	buffer->unlock();
}

int VertexBuffer::_set(int offset) {
	return buffer->_set(offset);
}

void VertexBufferImpl::unset() {
	if ((void*)current == (void*)this) current = nullptr;
	buffer->unset();
}

int VertexBuffer::count() {
	return buffer->count();
}

int VertexBuffer::stride() {
	return buffer->stride();
}

//int VertexBufferImpl::setVertexAttributes(int offset) {
//	return buffer->setVertexAttributes(offset);
//}
