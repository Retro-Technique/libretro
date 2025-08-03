#include <libretro/graphics.h>

int main(int argc, char* argv[])
{
	retro::graphics::window::info window_info
	{
		._title{"Simple Window"},
		._width{640},
		._height{480},
		._fullscreen{false}
	};

	retro::graphics::render_window render_window;

	bool succeeded = render_window.create(window_info);
	if (!succeeded)
	{
		return EXIT_FAILURE;
	}

	retro::graphics::vertex vertex;

	std::cout << vertex << std::endl;

	while (!render_window.should_close())
	{
		render_window.poll_events();
		render_window.begin_scene();
		render_window.end_scene();
	}

	return EXIT_SUCCESS;
}