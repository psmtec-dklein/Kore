#pragma once

#include <Kore/Math/Matrix.h>
#include <Kore/Math/Vector.h>
#include <Kore/Graphics4/VertexStructure.h>
#include <Kore/Graphics4/Shader.h>
#include <Kore/Graphics4/Types.h>
#include <Kore/Graphics5/GraphicsImpl.h>
#include <Kore/Graphics5/Shader.h>

namespace Kore {
	namespace Graphics5 {
		typedef Kore::Graphics4::VertexData VertexData;
		typedef Kore::Graphics4::VertexElement VertexElement;
		typedef Kore::Graphics4::VertexStructure VertexStructure;
		typedef Kore::Graphics4::CullMode CullMode;
		typedef Kore::Graphics4::StencilAction StencilAction;
		typedef Kore::Graphics4::BlendingOperation BlendingOperation;
		typedef Kore::Graphics4::ZCompareMode ZCompareMode;
		typedef Kore::Graphics4::RenderTarget RenderTarget;

		enum BlendingFactor {
			BlendingFactorUndefined,
			BlendingFactorBlendOne,
			BlendingFactorBlendZero,
			BlendingFactorSourceAlpha,
			BlendingFactorDestinationAlpha,
			BlendingFactorInverseSourceAlpha,
			BlendingFactorInverseDestinationAlpha
		};

		enum CompareMode {
			CompareModeAlways,
			CompareModeNever,
			CompareModeEqual,
			CompareModeNotEqual,
			CompareModeLess,
			CompareModeLessEqual,
			CompareModeGreater,
			CompareModeGreaterEqual
		};

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

		class PipelineState : PipelineStateImpl {
			VertexStructure inputLayout[8];
			Shader* vertexShader;
			Shader* fragmentShader;
			Shader* geometryShader;
			Shader* tesselationControlShader;
			Shader* tesselationEvaluationShader;

			CullMode cullMode;

			bool depthWrite;
			CompareMode depthMode;

			CompareMode stencilMode;
			StencilAction stencilBothPass;
			StencilAction stencilDepthFail;
			StencilAction stencilFail;
			int stencilReferenceValue;
			int stencilReadMask;
			int stencilWriteMask;

			// One, Zero deactivates blending
			BlendingFactor blendSource;
			BlendingFactor blendDestination;
			BlendingOperation blendOperation;
			BlendingFactor alphaBlendSource;
			BlendingFactor alphaBlendDestination;
			BlendingOperation alphaBlendOperation;

			bool colorWriteMaskRed;
			bool colorWriteMaskGreen;
			bool colorWriteMaskBlue;
			bool colorWriteMaskAlpha;
		};

		class CommandBuffer : CommandBufferImpl {
			void drawIndexedVertices();
			void drawIndexedVertices(int start, int count);
			void drawIndexedVerticesInstanced(int instanceCount);
			void drawIndexedVerticesInstanced(int instanceCount, int start, int count);

			void clearCurrent();

			void viewport(int x, int y, int width, int height);
			void scissor(int x, int y, int width, int height);
			void disableScissor();
			void setStencilParameters(ZCompareMode compareMode, StencilAction bothPass, StencilAction depthFail, StencilAction stencilFail, int referenceValue, int readMask = 0, int writeMask = 0);

			/*void setRenderState(RenderState state, bool on);
			void setRenderState(RenderState state, int v);
			void setRenderState(RenderState state, float value);
			void setTextureAddressing(TextureUnit unit, TexDir dir, TextureAddressing addressing);
			void setTextureMagnificationFilter(TextureUnit texunit, TextureFilter filter);
			void setTextureMinificationFilter(TextureUnit texunit, TextureFilter filter);
			void setTextureMipmapFilter(TextureUnit texunit, MipmapFilter filter);
			void setBlendingMode(BlendingOperation source, BlendingOperation destination);
			void setTextureOperation(TextureOperation operation, TextureArgument arg1, TextureArgument arg2);*/
			void setColorMask(bool red, bool green, bool blue, bool alpha);

			void clear(uint flags, uint color = 0, float depth = 1.0f, int stencil = 0);

			void setRenderTarget(RenderTarget* texture, int num = 0, int additionalTargets = 0);
			void restoreRenderTarget();

			void setVertexBuffer(VertexBuffer& vertexBuffer);
			void setVertexBuffers(VertexBuffer** vertexBuffers, int count);
			void setIndexBuffer(IndexBuffer& indexBuffer);

			void setTexture(TextureUnit unit, Texture* texture);
		};

		void setBool(ConstantLocation location, bool value);
		void setInt(ConstantLocation location, int value);
		void setFloat(ConstantLocation location, float value);
		void setFloat2(ConstantLocation location, float value1, float value2);
		void setFloat2(ConstantLocation location, vec2 value);
		void setFloat3(ConstantLocation location, float value1, float value2, float value3);
		void setFloat3(ConstantLocation location, vec3 value);
		void setFloat4(ConstantLocation location, float value1, float value2, float value3, float value4);
		void setFloat4(ConstantLocation location, vec4 value);
		void setFloats(ConstantLocation location, float* values, int count);
		void setMatrix(ConstantLocation location, const mat3& value);
		void setMatrix(ConstantLocation location, const mat4& value);

		//void changeResolution(int width, int height);
		bool hasWindow();
		void setWindow(bool);
		int antialiasingSamples();
		void setAntialiasingSamples(int samples);

		bool renderTargetsInvertedY();

		// TODO (DK) windowId should be renamed contextId?
		void setup();
		void swapBuffers(int windowId = 0);
		void begin(int windowId = 0);
		void end(int windowId = 0);
		void makeCurrent(int windowId);

		bool vsynced();
		unsigned refreshRate();
		bool nonPow2TexturesSupported();

		const uint ClearColorFlag = 1;
		const uint ClearDepthFlag = 2;
		const uint ClearStencilFlag = 4;

		void init(int windowId, int depthBufferBits, int stencilBufferBits);
		void destroy(int windowId);

		extern bool fullscreen;

		void flush();
	}
}