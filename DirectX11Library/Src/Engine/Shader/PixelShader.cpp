
#include "PixelShader.h"

bool shader::Pixcel::Create(ID3D11Device* p_Device_, const char* p_FileName_)
{
	if (!shader::Base::Create(p_Device_, p_FileName_)) return false;

	if (FAILED(p_Device_->CreatePixelShader(p_Data, p_Size, nullptr, &p_Interface))) return false;

	return true;
}
