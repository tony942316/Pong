/*
 * Copyright (C) 2023 Anthony H. Grasso
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef PONG_DETAILS_GAMEIMPL_IPP
#define PONG_DETAILS_GAMEIMPL_IPP

#include "GameDecl.hpp"

namespace pong
{
    inline void Game::play() noexcept
    {
        s_Window.init(1200, 800, "Pong"sv);
        s_Window.setUpdateFunc(update);
        s_Window.setRenderFunc(render);

        Renderer::boot();

        s_Window.show();
    }

    inline void Game::update() noexcept
    {
        auto keyW = pul::Keyboard::getKey(pul::Keyboard::Key::W);
        auto keyS = pul::Keyboard::getKey(pul::Keyboard::Key::S);
        auto keyR = pul::Keyboard::getKey(pul::Keyboard::Key::R);
        auto keySpace = pul::Keyboard::getKey(pul::Keyboard::Key::Space);

        if (keyW == pul::Keyboard::Button::Up &&
            keyS == pul::Keyboard::Button::Up)
        {
            s_Sim.setState(Simulation::PaddleType::Left,
                Simulation::Command::Stop);
        }
        else if (keyW == pul::Keyboard::Button::Down &&
            keyS == pul::Keyboard::Button::Down)
        {
            s_Sim.setState(Simulation::PaddleType::Left,
                Simulation::Command::Stop);
        }
        else if (keyW == pul::Keyboard::Button::Down)
        {
            s_Sim.setState(Simulation::PaddleType::Left,
                Simulation::Command::Up);
        }
        else if (keyS == pul::Keyboard::Button::Down)
        {
            s_Sim.setState(Simulation::PaddleType::Left,
                Simulation::Command::Down);
        }

        if (s_Sim.kickedOff() == false &&
            keySpace == pul::Keyboard::Button::Down)
        {
            s_Sim.kickOff();
        }

        if (keyR == pul::Keyboard::Button::Down)
        {
            s_Sim.reset();
        }

        s_Sim.update(s_Window.getDeltaTime());
    }

    inline void Game::render() noexcept
    {
        Renderer::render(s_Sim);
        //Ui::render();
    }
}

#endif // PONG_DETAILS_GAMEIMPL_IPP
