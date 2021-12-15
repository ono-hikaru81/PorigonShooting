
#ifndef SHADER_BASE_H
#define SHADER_BASE_H

#include <d3d11.h>
#include <stdio.h>

namespace shader
{
	class Base
	{
	public:
		Base() :
			p_Size(0),
			p_Data(nullptr) {}

		virtual ~Base()
		{
			if (p_Data != nullptr)
			{
				delete[] p_Data;
			}
		}

		inline const char* GetData() { return p_Data; }

		inline long GetSize() { return p_Size; }

		virtual bool Create(ID3D11Device* p_Device, const char* p_FileName_);

	private:
		int LoadFile(const char* p_FileName_);

	protected:
		/*
			union
			複数の型が同一のメモリ領域を共有する構造体のこと。
			共用体ともいう。
			処理系に依存するような情報を入れないで一つのメモリ領域で
			異なる種類のデータを処理できる。
		*/
		union ShaderInterface
		{
			ID3D11VertexShader* p_Vertex;
			ID3D11PixelShader* p_Pixel;
		};

		char* p_Data;
		long p_Size;
	};
};

#endif // !SHADER_BASE_H
