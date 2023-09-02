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

#ifndef PONG_DETAILS_SIMULATIONIMPL_IPP
#define PONG_DETAILS_SIMULATIONIMPL_IPP

#include "SimulationDecl.hpp"

namespace pong
{
    constexpr Simulation::Simulation() noexcept
        :
        m_KickedOff(false),
        m_Paddles(),
        m_Ball()
    {
        reset();
    }

    inline void Simulation::update(float dt) noexcept
    {
        static auto ballITimer = eqx::StopWatch();

        m_Ball.pos += m_Ball.dir * m_Ball.speed * dt;

        std::ranges::for_each(m_Paddles,
            [&](Paddle& paddle)
            {
                paddle.pos.y +=
                    static_cast<float>(paddle.dir) * paddle.speed * dt;
                paddle.pos.y = std::ranges::clamp(
                    paddle.pos.y, 0.0f, 800.0f - paddle.pos.h);

                if (eqx::intersect(paddle.pos, getBall()))
                {
                    if (m_Ball.cd == false)
                    {
                        m_Ball.dir.x *= -1;
                        m_Ball.cd = true;
                        ballITimer.start();
                    }
                    else if (ballITimer.readSeconds() > 0.3)
                    {
                        m_Ball.cd = false;
                    }
                }
            });
    }

    constexpr void Simulation::setState(PaddleType paddle,
        Command command) noexcept
    {
        m_Paddles.at(static_cast<std::size_t>(paddle)).dir =
            static_cast<int>(command);
    }

    inline void Simulation::kickOff() noexcept
    {
        m_Ball.dir = eqx::Point<float>(
            -1.0f + 2.0f * static_cast<float>(eqx::Random::flipCoin()),
            0.0f);
        m_KickedOff = true;
    }

    constexpr void Simulation::reset() noexcept
    {
        m_KickedOff = false;

        m_Paddles.at(static_cast<std::size_t>(PaddleType::Left)).dir = 0;
        m_Paddles.at(static_cast<std::size_t>(PaddleType::Left)).speed = 500.0f;
        m_Paddles.at(static_cast<std::size_t>(PaddleType::Left)).pos =
            eqx::Rectangle<float>(
                0.0f + 10.0f,
                400.0f - 150.0f / 2.0f,
                25.0f,
                150.0f);

        m_Paddles.at(static_cast<std::size_t>(PaddleType::Right)).dir = 0;
        m_Paddles.at(static_cast<std::size_t>(PaddleType::Right)).speed =
            500.0f;
        m_Paddles.at(static_cast<std::size_t>(PaddleType::Right)).pos =
            eqx::Rectangle<float>(
                1200.0f - 25.0f - 10.0f,
                400.0f - 150.0f / 2.0f,
                25.0f,
                150.0f);

        m_Ball.cd = false;
        m_Ball.radius = 10.0f;
        m_Ball.speed = 500.0f;
        m_Ball.dir = eqx::Point<float>();
        m_Ball.pos = eqx::Point<float>(
            600.0f - m_Ball.radius,
            400.0f - m_Ball.radius);
    }

    constexpr bool Simulation::kickedOff() const noexcept
    {
        return m_KickedOff;
    }

    constexpr const eqx::Rectangle<float>& Simulation::getPaddle(
        PaddleType paddle) const noexcept
    {
        return m_Paddles.at(static_cast<std::size_t>(paddle)).pos;
    }

    constexpr eqx::Rectangle<float> Simulation::getBall() const noexcept
    {
        return eqx::Rectangle<float>(
            m_Ball.pos.x,
            m_Ball.pos.y,
            m_Ball.radius * 2.0f,
            m_Ball.radius * 2.0f);
    }
}

#endif // PONG_DETAILS_SIMULATIONIMPL_IPP
