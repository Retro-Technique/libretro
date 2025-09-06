#include <libretro/graphics.h>

int main(int argc, char* argv[])
{
	try
	{
		retro::graphics::window window("Simple Window", { 640, 480 }, false, false);
		retro::graphics::renderer renderer(window);

		while (!window.should_close())
		{
			window.poll_events();
			renderer.clear();
			window.swap_buffers();
		}
	}
	catch (const std::exception& e)
	{
		BOOST_LOG_TRIVIAL(error) << e.what();
	}

	return EXIT_SUCCESS;
}