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

#ifndef PONG_DETAILS_GAMEDECL_HPP
#define PONG_DETAILS_GAMEDECL_HPP

#include "Dependencies.hpp"

#include "../Simulation.hpp"

namespace pong
{
    class Game
    {
    public:
        Game() = delete;
        Game(const Game&) = delete;
        Game(Game&&) = delete;
        Game& operator= (const Game&) = delete;
        Game& operator= (Game&&) = delete;
        ~Game() = delete;

        static inline void play() noexcept;

    private:
        static inline void update() noexcept;
        static inline void render() noexcept;

        constinit static inline auto s_Window = pul::Window();
        constinit static inline auto s_Box = pul::Quad();
        constinit static inline auto s_Box2 = pul::Quad();
        constinit static inline auto s_Box3 = pul::Quad();
        constinit static inline auto s_Sim = Simulation(
            eqx::Rectangle<float>(0.0f, 0.0f, 1200.0f, 800.0f));
    };
}

#endif // PONG_DETAILS_GAMEDECL_HPP
