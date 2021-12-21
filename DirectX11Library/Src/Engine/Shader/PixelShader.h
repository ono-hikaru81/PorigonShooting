
#ifndef PIXEL_SHADER_H
#define PIXEL_SHADER_H

#include <d3d11.h>

#include "ShaderBase.h"

namespace shader
{
	class Pixcel : public Base
	{
	public:
		Pixcel() :
			p_Interface(nullptr) {}

		virtual ~Pixcel()
		{
			if (p_Interface != nullptr)
			{
				p_Interface->Release();
			}
		}

		virtual bool Create(ID3D11Device* p_Device_, const char* p_FileName_);

		ID3D11PixelShader* GetShagerInterface() { return p_Interface; }

	private:
		ID3D11PixelShader* p_Interface;
	};
};

#endif // !PIXEL_SHADER_H
