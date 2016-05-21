#pragma once

namespace Kore {
	namespace Graphics4 {
		class RenderTargetImpl {
		public:
			VkImage destImage;
			VkDeviceMemory destMemory;
			VkImageView destView;

			VkImage sourceImage;
			VkDeviceMemory sourceMemory;
			VkImageView sourceView;

			VkFramebuffer framebuffer;
			VkDescriptorSet desc_set;
			VkSampler sampler;
			VkRenderPass renderPass;
		};
	}
}
