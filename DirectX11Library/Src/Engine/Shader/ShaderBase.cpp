
#include "ShaderBase.h"

#include <d3dcompiler.h>

#pragma comment(lib, "d3dcompiler.lib")

bool shader::Base::Create(ID3D11Device* p_Device, const char* p_FileName_)
{
	p_Size = LoadFile(p_FileName_);
	if (p_Size == 0) return false;

	return true;
}

int shader::Base::LoadFile(const char* p_FileName_)
{
	/*
		fopen_s
		ファイルを開く。
		第一引数:: ファイル構造体のポインタ変数へのポインタを指定する
				   「ポインタへのポインタ」
				   =>ポインタ変数にアドレス演算子を付けて指定する
		第二引数:: ファイル名の指定
		第三引数:: ファイルのオープンモードを指定
				   rb => バイナリファイル
						 読み取りモードで開く
						 存在しない場合はエラー

		fseek
		ファイルポインタの位置を指定した位置に移動させることができる
		第一引数:: ファイルポインタ
		第二引数:: どれだけ(何バイト)移動させるかのオフセット値
		第三引数:: どの位置から移動させるかの定数
				   SEEK_SET => ファイルの先頭から
				   SEEK_CUR => ファイルの現在位置から
				   SEEK_END => ファイルの終端から

		ftell
		現在のファイル位置の値を得る。

		fread_s
		第一引数:: データの格納場所
		第二引数:: ターゲットバッファーのサイズ(バイト単位)
		第三引数:: 読み取る項目のサイズサイズ(バイト単位)
		第四引数:: 読み取る項目の最大数
		第五引数:: ファイル構造体へのポインタ

		fclose
		開いたファイルを閉じる
	*/
	// シェーダファイル読み込み
	FILE* fp = nullptr;
	fopen_s(&fp, p_FileName_, "rb");

	if (fp == nullptr) return 0;

	fseek(fp, 0, SEEK_END);
	p_Size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	p_Data = new char[p_Size];
	fread_s(p_Data, p_Size, p_Size, 1, fp);
	fclose(fp);

	return p_Size;
}
