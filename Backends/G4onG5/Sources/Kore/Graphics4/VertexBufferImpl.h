#pragma once

namespace Kore {
	namespace Graphics5 {
		class VertexBuffer;
	}

	namespace Graphics4 {
		class VertexBuffer;
		class VertexStructure;

		class VertexBufferImpl {
		protected:
			VertexBufferImpl(int count, const VertexStructure& structure, int instanceDataStepRate);
			void unset();
			
			Graphics5::VertexBuffer* buffer;
		public:
			static VertexBuffer* current;
		};
	}
}
