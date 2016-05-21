#pragma once

namespace Kore {
	namespace Graphics5 {
		class Program;
		class ProgramImpl;

		class ShaderImpl {
		public:
			ShaderImpl(void* source, int length);
			virtual ~ShaderImpl();
			uint id;
			char* source;
			int length;
			friend class Program;
			friend class ProgramImpl;
		};
	}
}
