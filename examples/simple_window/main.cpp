#include <libretro/graphics.h>
#include <boost/log/trivial.hpp>

int main(int argc, char* argv[])
{
	int ret = EXIT_SUCCESS;

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
		ret = EXIT_FAILURE;
	}

	return ret;
}