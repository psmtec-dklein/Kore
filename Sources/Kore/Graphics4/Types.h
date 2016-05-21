#pragma once

#include <Kore/Graphics4/IndexBufferImpl.h>
#include <Kore/Graphics4/VertexBufferImpl.h>
#include <Kore/Graphics4/RenderTargetImpl.h>

namespace Kore {
	namespace Graphics4 {
		class VertexBuffer : public VertexBufferImpl {
		public:
			VertexBuffer(int count, const VertexStructure& structure, int instanceDataStepRate = 0);
			virtual ~VertexBuffer();
			float* lock();
			float* lock(int start, int count);
			void unlock();
			int count();
			int stride();
			int _set(int offset = 0); // Do not call this directly, use Graphics::setVertexBuffers
		};

		class IndexBuffer : public IndexBufferImpl {
		public:
			IndexBuffer(int count);
			virtual ~IndexBuffer();
			int* lock();
			void unlock();
			int count();
			void _set();
		};

		enum TextureAddressing {
			Repeat,
			Mirror,
			Clamp,
			Border
		};

		enum TextureFilter {
			PointFilter,
			LinearFilter,
			AnisotropicFilter
		};

		enum MipmapFilter {
			NoMipFilter,
			PointMipFilter,
			LinearMipFilter //linear texture filter + linear mip filter -> trilinear filter
		};

		enum RenderState {
			BlendingState, DepthTest, DepthTestCompare, /*Lighting,*/ DepthWrite, Normalize, BackfaceCulling, /*FogState, FogStartState, FogEndState, FogTypeState, FogColorState,*/ ScissorTestState,
			AlphaTestState, AlphaReferenceState
		};

		enum BlendingOperation {
			BlendOne,
			BlendZero,
			SourceAlpha,
			DestinationAlpha,
			InverseSourceAlpha,
			InverseDestinationAlpha
		};

		enum ZCompareMode {
			ZCompareAlways,
			ZCompareNever,
			ZCompareEqual,
			ZCompareNotEqual,
			ZCompareLess,
			ZCompareLessEqual,
			ZCompareGreater,
			ZCompareGreaterEqual
		};

		enum CullMode {
			Clockwise,
			CounterClockwise,
			NoCulling
		};

		enum TexDir {
			U, V
		};

		enum FogType {
			LinearFog
		};

		enum RenderTargetFormat {
			Target32Bit,
			Target64BitFloat,
			Target32BitRedFloat,
			Target128BitFloat,
			Target16BitDepth
		};

		enum StencilAction {
			Keep,
			Zero,
			Replace,
			Increment,
			IncrementWrap,
			Decrement,
			DecrementWrap,
			Invert
		};

		enum TextureOperation {
			ModulateOperation,
			SelectFirstOperation,
			SelectSecondOperation
		};

		enum TextureArgument {
			CurrentColorArgument,
			TextureColorArgument
		};

		class RenderTarget : public RenderTargetImpl {
		public:
			RenderTarget(int width, int height, int depthBufferBits, bool antialiasing = false, RenderTargetFormat format = Target32Bit, int stencilBufferBits = -1, int contextId = 0);
			int width;
			int height;
			int texWidth;
			int texHeight;
			int contextId;
			void useColorAsTexture(TextureUnit unit);
			//void useDepthAsTexture(int texunit);
		};
	}
}
