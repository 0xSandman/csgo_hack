struct vertex_t
{
	float x, y, z, rhw;
	D3DCOLOR color;

	vertex_t() : x(0.0f), y(0.0f), z(1.0f), rhw(1.0f), color(0) {}
	vertex_t(float x_, float y_, float z_, float rhw_, D3DCOLOR color_) : x(x_), y(y_), z(z_), rhw(rhw_), color(color_) {}
	vertex_t(vec2_t pos, float rhw_, D3DCOLOR color_) : x(pos.x), y(pos.y), z(0.0f), rhw(rhw_), color(color_) {}
};

class c_render
{
public:
	c_render(IDirect3DDevice9* Device)
	{
		this->device = Device;
		this->vertex_shader = vertex_shader;

		Device->GetViewport(&screen_size);
	}

	void rectangle(float x, float y, float w, float h, D3DCOLOR color);
	void setup_render_states();
	void save_state();
	void restore_state();
	void line(float x, float y, float x2, float y2, D3DCOLOR color);
	void outline(float x, float y, float w, float h, D3DCOLOR color);
	int get_text_width(const char* text, LPD3DXFONT font);
	void text(float x, float y, LPD3DXFONT font, std::string text, D3DCOLOR color, bool centered = false, bool drop_shadow = false, D3DCOLOR shadow_color = D3DCOLOR());

	IDirect3DVertexShader9* vertex_shader;
	IDirect3DDevice9* device;
	IDirect3DVertexDeclaration9* vertext_declaration;
	IDirect3DVertexShader9* vertex_shader2;
	IDirect3DPixelShader9* pixel_shader;
	DWORD dwold_d3drs_colorwriteenable;
	DWORD dwold_d3dtexturestagestate;
	DWORD dwold_d3drs_antialiasedlineenable;
	DWORD dwold_d3drs_multisampleantialias;
	RECT rect_old_scissor_rect;
	D3DVIEWPORT9 screen_size;

}; extern c_render* render;