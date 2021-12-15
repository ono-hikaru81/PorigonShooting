
#ifndef MODEL_DATA_H
#define MODEL_DATA_H

#include <d3d11.h>

#include "Shader/VertexShader.h"

namespace DirectX
{
	class PolygonData
	{
	public:
		PolygonData() :
			p_VertexBuffer(nullptr),
			p_IndexBuffer(nullptr),
			p_InputLayout(nullptr)
		{
		}

		~PolygonData()
		{
			if (p_VertexBuffer != nullptr)
			{
				p_VertexBuffer->Release();
			}

			if (p_IndexBuffer != nullptr)
			{
				p_IndexBuffer->Release();
			}

			if (p_InputLayout != nullptr)
			{
				p_InputLayout->Release();
			}
		}

	public:
		ID3D11Buffer* GetVertexBuffer() { return p_VertexBuffer; }
		ID3D11Buffer* GetIndexBuffer() { return p_IndexBuffer; }
		ID3D11InputLayout* GetInputLayout() { return p_InputLayout; }

	public:
		bool CreatePorigon(ID3D11Device* device_, shader::Vertex* vertexShader_);
		bool CreateRect(ID3D11Device* device_, shader::Vertex* vertexShader_);
		bool CreateCube(ID3D11Device* device_, shader::Vertex* vertexShader_);

	private:
		ID3D11Buffer* p_VertexBuffer;
		ID3D11Buffer* p_IndexBuffer;
		ID3D11InputLayout* p_InputLayout;
	};
};

#endif // !MODEL_DATA_H
