#pragma once

#include "IndexBufferImpl.h"
#include "VertexBufferImpl.h"
#include "../Graphics4/TextureImpl.h"
#include "RenderTargetImpl.h"

#include <vulkan/vulkan.h>

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef RegisterClass
#undef RegisterClass
#endif

namespace Kore {
	namespace Graphics5 {
		class PipelineStateImpl {

		};

		class CommandBufferImpl {
		public:
			VkCommandBuffer commandBuffer;
		};
	}
}
