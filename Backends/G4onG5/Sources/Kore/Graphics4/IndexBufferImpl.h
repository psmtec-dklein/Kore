#pragma once

namespace Kore {
	namespace Graphics5 {
		class IndexBuffer;
	}

	namespace Graphics4 {
		class IndexBuffer;

		class IndexBufferImpl {
		protected:
		public:
			IndexBufferImpl(int count);
			void unset();

			Graphics5::IndexBuffer* buffer;
		public:
			static IndexBuffer* current;
		};
	}
}
