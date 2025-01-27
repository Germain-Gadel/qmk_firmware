/* Copyright 2021 Germain Gadel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
  k01, k02, k03, k04, k05,    k55, k54, k53, k52, k51, \
  k11, k12, k13, k14, k15,    k65, k64, k63, k62, k61, \
  k21, k22, k23, k24, k25,    k75, k74, k73, k72, k71, \
  k31, k32, k33, k34, k35,    k85, k84, k83, k82, k81, \
            k43, k44, k45,    k95, k94, k93            \
  ) \
  { \
    { k01, k02, k03, k04, k05 }, \
    { k11, k12, k13, k14, k15 }, \
    { k21, k22, k23, k24, k25 }, \
    { k31, k32, k33, k34, k35 }, \
    { KC_NO, KC_NO, k43, k44, k45 }, \
    { k51, k52, k53, k54, k55 }, \
    { k61, k62, k63, k64, k65 }, \
    { k71, k72, k73, k74, k75 }, \
    { k81, k82, k83, k84, k85 }, \
    { KC_NO, KC_NO, k93, k94, k95 } \
  }
