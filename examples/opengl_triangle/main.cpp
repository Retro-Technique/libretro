#include "pch.h"

int main(int argc, char* argv[])
{
	try
	{
		rg::window window("OpenGL Triangle", { 640, 480 }, false, false);
		rg::renderer renderer(window);
		
		const rg::matrix4x4 projection = rg::matrix4x4::ortho(0.f, 640.f, 480.f, 0.f);
		const rg::matrix4x4 view;

		const rg::vertex_shader_source vs(VERTEX_SHADER);
		const rg::fragment_shader_source fs(FRAGMENT_SHADER);
		const rg::shader_program sp(fs, vs);
		const rg::vertex_buffer vbo(VERTICES);
		const rg::vertex_array vao(vbo, rg::topology::triangles, sp, "vPos", "vCol");
		const rg::blend_mode bm(rg::blend::alpha);
		const rg::matrix4x4 model;

		while (!window.should_close())
		{
			window.poll_events();
			renderer.viewport({ 0, 0, 640, 480 });
			renderer.clear();
			renderer.draw(vbo, vao, bm, sp, model, view, projection);
			window.swap_buffers();
		}
	}
	catch (const std::exception& e)
	{
		BOOST_LOG_TRIVIAL(error) << e.what();
	}

	return EXIT_SUCCESS;
}