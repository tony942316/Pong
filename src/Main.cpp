#include "Pulsar/Pulsar.hpp"

constinit inline auto g_Window = pul::Window();

void update() noexcept
{

}

void render() noexcept
{

}

int main()
{
    std::cout << "Start" << std::endl;

    g_Window.init(1200, 800, "Pong");
    g_Window.setUpdateFunc(update);
    g_Window.setRenderFunc(render);

    g_Window.show();

    std::cout << "End" << std::endl;
    return 0;
}
