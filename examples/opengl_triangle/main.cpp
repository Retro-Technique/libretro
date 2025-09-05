#include "pch.h"
#include "triangle.h"

int main(int argc, char* argv[])
{
	try
	{
		retro::graphics::window::info window_info
		{
			._title{"OpenGL Triangle"},
			._size{640, 480},
			._fullscreen{false}
		};

		retro::graphics::render_window render_window;

		bool succeeded = render_window.create(window_info);
		if (!succeeded)
		{
			return EXIT_FAILURE;
		}

		retro::graphics::shader shader(VERTEX_SHADER, FRAGMENT_SHADER);

		triangle triangle(shader);

		while (!render_window.should_close())
		{
			render_window.poll_events();
			render_window.begin_scene();
			render_window.draw(triangle);
			render_window.end_scene();
		}
	}
	catch (const std::exception& e)
	{
		BOOST_LOG_TRIVIAL(error) << e.what();
	}

	return EXIT_SUCCESS;
}