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

#ifndef PONG_DETAILS_RENDERERDECL_HPP
#define PONG_DETAILS_RENDERERDECL_HPP

#include "Dependencies.hpp"

#include "../Simulation.hpp"

namespace pong
{
    class Renderer
    {
    public:
        Renderer() = delete;
        Renderer(const Renderer&) = delete;
        Renderer(Renderer&&) = delete;
        Renderer& operator= (const Renderer&) = delete;
        Renderer& operator= (Renderer&&) = delete;
        ~Renderer() = delete;

        static inline void render(const Simulation& sim) noexcept;

        static inline void boot() noexcept;
    private:

        static inline auto s_LeftPaddle = pul::CQuad();
        static inline auto s_RightPaddle = pul::CQuad();
        static inline auto s_Ball = pul::CQuad();
    };
}

#endif // PONG_DETAILS_RENDERERDECL_HPP
