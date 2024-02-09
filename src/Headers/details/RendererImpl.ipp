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

#ifndef PONG_DETAILS_RENDERERIMPL_IPP
#define PONG_DETAILS_RENDERERIMPL_IPP

#include "RendererDecl.hpp"

namespace pong
{
    inline void Renderer::render(const Simulation& sim) noexcept
    {
        s_LeftPaddle.setRect(sim.getPaddle(Simulation::PaddleType::Left));
        s_RightPaddle.setRect(sim.getPaddle(Simulation::PaddleType::Right));
        s_Ball.setRect(sim.getBall());

        pul::Renderer::draw(s_LeftPaddle);
        pul::Renderer::draw(s_RightPaddle);
        pul::Renderer::draw(s_Ball);
    }

    inline void Renderer::boot() noexcept
    {
        s_LeftPaddle.setColor(pul::CQuad::color(0.8f, 0.0f, 0.2f));
        s_RightPaddle.setColor(pul::CQuad::color(0.2f, 0.0f, 0.8f));
        s_Ball.setColor(pul::CQuad::color(0.0f, 0.8f, 0.2f));
    }
}

#endif // PONG_DETAILS_RENDERERIMPL_IPP
