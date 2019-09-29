#include "../source_development_kit/source_development_kit.hh"

// fixme: sloppily ported over from my last project

void c_render::rectangle(float x, float y, float w, float h, D3DCOLOR color)
{
	vertex_t Vertices[4] =
	{
		{ x, y, 0.0f, 1.0f, color },
		{ x + w, y, 0.0f, 1.0f, color },
		{ x, y + h, 0.0f, 1.0f, color },
		{ x + w, y + h, 0.0f, 1.0f, color }
	};

	this->device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	this->device->SetTexture(0, nullptr);
	this->device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Vertices, sizeof(vertex_t));
}

void c_render::line(float x, float y, float x2, float y2, D3DCOLOR color)
{
	vertex_t vert[2] =
	{
		{ x, y, 1.0f, 1.0f, color },
		{ x2, y2, 1.0f, 1.0f, color },
	};

	this->device->SetTexture(0, nullptr);
	this->device->DrawPrimitiveUP(D3DPT_LINELIST, 1, &vert, sizeof(vertex_t));
}

void c_render::outline(float x, float y, float w, float h, D3DCOLOR color)
{
	vertex_t vert[5] =
	{
		{ x, y, 1.0f, 1.0f, color },
		{ x + w, y, 1.0f, 1.0f, color },
		{ x + w, y + h, 1.0f, 1.0f, color },
		{ x, y + h, 1.0f, 1.0f, color },
		{ x, y, 1.0f, 1.0f, color }
	};

	this->device->SetTexture(0, nullptr);
	this->device->DrawPrimitiveUP(D3DPT_LINESTRIP, 4, &vert, sizeof(vertex_t));
}

int c_render::get_text_width(const char* text, LPD3DXFONT font)
{
	RECT rcRect = { 0,0,0,0 };
	if (font)
	{
		font->DrawText(NULL, text, strlen(text), &rcRect, DT_CALCRECT,
			D3DCOLOR_XRGB(0, 0, 0));
	}

	return rcRect.right - rcRect.left;
}

void c_render::text(float x, float y, LPD3DXFONT font, std::string text, D3DCOLOR color, bool centered, bool drop_shadow, D3DCOLOR shadow_color)
{
	if (centered)
	{
		x -= (get_text_width(text.c_str(), font) / 2);
	}

	RECT DrawArea = { x, y, 1920, DrawArea.top + 200 };

	if (drop_shadow)
	{
		RECT DrawArea2 = { x + 1.f, y, 1920, DrawArea.top + 200 };
		RECT DrawArea3 = { x - 1.f, y, 1920, DrawArea.top + 200 };
		RECT DrawArea4 = { x, y + 1.f, 1920, DrawArea.top + 200 };
		RECT DrawArea5 = { x, y - 1.f, 1920, DrawArea.top + 200 };
		font->DrawTextA(NULL, text.c_str(), -1, &DrawArea2, 0, shadow_color);
		font->DrawTextA(NULL, text.c_str(), -1, &DrawArea3, 0, shadow_color);
		font->DrawTextA(NULL, text.c_str(), -1, &DrawArea4, 0, shadow_color);
		font->DrawTextA(NULL, text.c_str(), -1, &DrawArea5, 0, shadow_color);
	}

	font->DrawTextA(NULL, text.c_str(), -1, &DrawArea, 0, color);
}

void c_render::setup_render_states()
{
	this->device->SetVertexShader(nullptr);
	this->device->SetPixelShader(nullptr);
	this->device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	this->device->SetRenderState(D3DRS_FOGENABLE, FALSE);
	this->device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	this->device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	this->device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	this->device->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);
	this->device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	this->device->SetRenderState(D3DRS_STENCILENABLE, FALSE);

	this->device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
	this->device->SetRenderState(D3DRS_ANTIALIASEDLINEENABLE, TRUE);

	this->device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	this->device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	this->device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, TRUE);
	this->device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	this->device->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_INVDESTALPHA);
	this->device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	this->device->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_ONE);

	this->device->SetRenderState(D3DRS_SRGBWRITEENABLE, FALSE);
	this->device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_RED | D3DCOLORWRITEENABLE_GREEN |
		D3DCOLORWRITEENABLE_BLUE | D3DCOLORWRITEENABLE_ALPHA);
}

void c_render::save_state()
{
	this->device->GetRenderState(D3DRS_COLORWRITEENABLE, &dwold_d3drs_colorwriteenable);
	this->device->GetRenderState(D3DRS_ANTIALIASEDLINEENABLE, &dwold_d3drs_antialiasedlineenable);
	this->device->GetRenderState(D3DRS_MULTISAMPLEANTIALIAS, &dwold_d3drs_multisampleantialias);
	this->device->GetTextureStageState(0, D3DTSS_COLORARG0, &dwold_d3dtexturestagestate);
	this->device->GetScissorRect(&rect_old_scissor_rect);
	this->device->GetVertexDeclaration(&vertext_declaration);
	this->device->GetVertexShader(&vertex_shader2);
	this->device->GetPixelShader(&pixel_shader);
	this->device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xffffffff);
	this->device->SetRenderState(D3DRS_SRGBWRITEENABLE, false);
	this->device->SetSamplerState(NULL, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	this->device->SetSamplerState(NULL, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	this->device->SetSamplerState(NULL, D3DSAMP_ADDRESSW, D3DTADDRESS_WRAP);
	this->device->SetSamplerState(NULL, D3DSAMP_SRGBTEXTURE, NULL);
	this->device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
}

void c_render::restore_state()
{
	device->SetTextureStageState(0, D3DTSS_COLORARG0, dwold_d3dtexturestagestate);
	device->SetRenderState(D3DRS_COLORWRITEENABLE, dwold_d3drs_colorwriteenable);
	device->SetRenderState(D3DRS_ANTIALIASEDLINEENABLE, dwold_d3drs_antialiasedlineenable);
	device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, dwold_d3drs_multisampleantialias);
	device->SetScissorRect(&rect_old_scissor_rect);
	this->device->SetRenderState(D3DRS_COLORWRITEENABLE, dwold_d3drs_colorwriteenable);

	device->SetRenderState(D3DRS_SRGBWRITEENABLE, true);
	device->SetVertexDeclaration(vertext_declaration);
	device->SetVertexShader(vertex_shader2);
	device->SetPixelShader(pixel_shader);
}