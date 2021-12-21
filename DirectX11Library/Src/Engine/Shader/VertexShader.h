
#ifndef VERTEX_SHADER_H
#define VERTEX_SHADER_H

#include <d3d11.h>

#include "ShaderBase.h"

namespace shader
{
	class Vertex : public shader::Base
	{
	public:
		Vertex() :
			p_Interface(nullptr) {};

		virtual ~Vertex()
		{
			if (p_Interface != nullptr)
			{
				p_Interface->Release();
			}
		}

		virtual bool Create(ID3D11Device* p_Device_, const char* p_FileName_);

		ID3D11VertexShader* GetShaderInterface() { return p_Interface; }

	private:
		ID3D11VertexShader* p_Interface;
	};
};

#endif // !VERTEX_SHADER_H
