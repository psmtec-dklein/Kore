#pragma once

#include <Kore/Math/Matrix.h>
#include <Kore/Graphics4/VertexStructure.h>
#include <Kore/Graphics4/ShaderImpl.h>
#include <Kore/Graphics4/ProgramImpl.h>
#include "../Graphics4/Texture.h"

namespace Kore {
	namespace Graphics5 {
		enum ShaderType {
			FragmentShader, VertexShader, GeometryShader, TesselationControlShader, TesselationEvaluationShader, ComputeShader
		};

		class Shader : public ShaderImpl {
		public:
			Shader(void* source, int length, ShaderType type);
		};

		class ConstantLocation : public ConstantLocationImpl {

		};

		class Program : public ProgramImpl {
		public:
			Program();
			void setVertexShader(Shader* shader);
			void setFragmentShader(Shader* shader);
			void setGeometryShader(Shader* shader);
			void setTesselationControlShader(Shader* shader);
			void setTesselationEvaluationShader(Shader* shader);
			void link(Graphics4::VertexStructure& structure) {
				Graphics4::VertexStructure* structures[1] = { &structure };
				link(structures, 1);
			}
			void link(Graphics4::VertexStructure** structures, int count);
			ConstantLocation getConstantLocation(const char* name);
			TextureUnit getTextureUnit(const char* name);
			void set();
		};
	}
}
