#include "pch.h"

int main(int argc, char* argv[])
{
	int ret = EXIT_SUCCESS;

	try
	{
		std::vector<rg::vertex> vertices = build_vertices(MAP, MAP_W, MAP_H);

		rg::window window("Sprite Batching", { 320, 240 }, false, false);
		rg::renderer renderer(window);
		
		ri::bitmap bitmap(RESOURCE_DIRECTORY "/sheet.png");

		const rg::matrix4x4 projection = rg::matrix4x4::ortho(0.f, 320, 240, 0.f);
		const rg::matrix4x4 view;

		const rg::vertex_shader_source vs(VERTEX_SHADER);
		const rg::fragment_shader_source fs(FRAGMENT_SHADER);
		const rg::shader_program sp(fs, vs);
		const rg::vertex_buffer vbo(vertices);
		const rg::texture tex(bitmap.data(), bitmap.size(), false, true);
		const rg::vertex_array vao(rg::topology::triangles, vbo, sp, "vPos", "vCol", tex, "vTexCoord");		
		const rg::blend_mode bm(rg::blend::alpha);
		const rg::matrix4x4 model;

		while (!window.should_close())
		{
			window.poll_events();
			renderer.viewport({ 0, 0, 320, 240 });
			renderer.clear();
			renderer.draw(vbo, vao, bm, sp, tex, model, view, projection);
			window.swap_buffers();
		}
	}
	catch (const std::exception& e)
	{
		BOOST_LOG_TRIVIAL(error) << e.what();
		ret = EXIT_FAILURE;
	}

	return ret;
}