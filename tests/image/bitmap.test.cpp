#include <boost/test/unit_test.hpp>
#include <libretro/image.h>
#include <fstream>

const std::filesystem::path res_dir = TESTS_RESOURCE_DIRECTORY;
const std::vector<std::string> image_files = { "TR.png", "TR.jpg", "TR.bmp" };

BOOST_AUTO_TEST_SUITE(BitmapSuite)

BOOST_AUTO_TEST_CASE(LoadFromFileValidImages)
{
    try
    {
        for (const auto& file : image_files)
        {
            retro::image::bitmap bmp(res_dir / file);

            BOOST_TEST(bmp.size().w > 0);
            BOOST_TEST(bmp.size().h > 0);
        }
    }
    catch (const std::exception& e)
    {
        BOOST_ERROR(e.what());
    }
}

BOOST_AUTO_TEST_CASE(LoadFromFileInvalidPath)
{
    BOOST_CHECK_THROW(retro::image::bitmap bmp("tests/res/does_not_exist.png"), std::exception);
}

/*

BOOST_AUTO_TEST_CASE(SaveToFileAndReload)
{
    for (const auto& file : image_files)
    {
        retro::image::bitmap bmp;

        bmp.load_from_file(res_dir / file);

        std::filesystem::path tmp_path = res_dir / ("tmp_" + file);
        std::ofstream(tmp_path.string()).close();

        BOOST_CHECK_NO_THROW(bmp.save_to_file(tmp_path));

        retro::image::bitmap bmp2;

        bmp2.load_from_file(tmp_path);

        BOOST_TEST(bmp.width() == bmp2.width());
        BOOST_TEST(bmp.height() == bmp2.height());
        BOOST_TEST(bmp.size() == bmp2.size());
        BOOST_TEST(bmp.size() > 0);

        std::filesystem::remove(tmp_path);
    }
}

BOOST_AUTO_TEST_CASE(SaveToFileInvalidPath)
{
    retro::image::bitmap bmp;

    bmp.load_from_file(res_dir / image_files[0]);

    BOOST_CHECK_THROW(bmp.save_to_file("tests/res/does_not_exist.png"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(SaveToFileEmptyBitmap)
{
    retro::image::bitmap bmp;

    std::filesystem::path tmp_path = res_dir / "tmp_empty.png";

    std::ofstream(tmp_path.string()).close();

    BOOST_CHECK_NO_THROW(bmp.save_to_file(tmp_path));

    std::filesystem::remove(tmp_path);
}
*/
BOOST_AUTO_TEST_SUITE_END()