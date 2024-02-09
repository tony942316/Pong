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

#ifndef PONG_DETAILS_SIMULATIONDECL_HPP
#define PONG_DETAILS_SIMULATIONDECL_HPP

#include "Dependencies.hpp"

namespace pong
{
    class Simulation
    {
    public:
        enum class PaddleType : std::size_t
        {
            Left = 0_size,
            Right = 1_size
        };

        enum class Command : int
        {
            Up = -1,
            Down = 1,
            Stop = 0
        };

        explicit constexpr Simulation(
            const eqx::Rectangle<float>& court) noexcept;

        inline void update(float dt) noexcept;

        constexpr void setState(PaddleType paddle, Command command) noexcept;
        inline void kickOff() noexcept;
        constexpr void reset() noexcept;

        constexpr bool kickedOff() const noexcept;
        constexpr const eqx::Rectangle<float>& getPaddle(
            PaddleType paddle) const noexcept;
        constexpr eqx::Rectangle<float> getBall() const noexcept;

    private:
        struct Paddle
        {
            explicit consteval Paddle() noexcept
                :
                dir(0),
                speed(0.0f),
                pos()
            {

            }

            int dir;
            float speed;
            eqx::Rectangle<float> pos;
        };

        struct Ball
        {
            explicit consteval Ball() noexcept
                :
                cd(false),
                radius(0.0f),
                speed(0.0f),
                dir(),
                pos()
            {

            }

            bool cd;
            float radius;
            float speed;
            eqx::Point<float> dir;
            eqx::Point<float> pos;
        };

        bool m_KickedOff;

        eqx::Rectangle<float> m_Court;

        std::array<Paddle, 2_size> m_Paddles;
        Ball m_Ball;
    };
}

#endif // PONG_DETAILS_SIMULATIONDECL_HPP
