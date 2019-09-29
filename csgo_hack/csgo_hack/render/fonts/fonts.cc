#include "../../source_development_kit/source_development_kit.hh"

LPD3DXFONT fonts::main_font;

void fonts::setup(IDirect3DDevice9* device)
{
	D3DXCreateFont(device, 13, 0, 900, 4, FALSE, DEFAULT_CHARSET, 1, DEFAULT_QUALITY, DEFAULT_PITCH, "Tahoma", &fonts::main_font);
}

void fonts::release()
{
	fonts::main_font->Release();
}