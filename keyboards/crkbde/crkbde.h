// Copyright 2022 Germain_Gadel (@Germain_Gadel)
// SPDX-License-Identifier: GPL-2.0-or-later

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
#define LAYOUT_split_3x5_3( \
        k01, k02, k03, k04, k05,    k55, k54, k53, k52, k51, \
        k11, k12, k13, k14, k15,    k65, k64, k63, k62, k61, \
        k21, k22, k23, k24, k25,    k75, k74, k73, k72, k71, \
             k32, k33, k34, k35,    k85, k84, k83, k82       \
    ) \
    { \
        { k01, k02, k03, k04, k05 },     \
        { k11, k12, k13, k14, k15 },     \
        { k21, k22, k23, k24, k25 },     \
        { KC_NO, k32, k33, k34, k35 }, \
        { k51, k52, k53, k54, k55 },     \
        { k61, k62, k63, k64, k65 },     \
        { k71, k72, k73, k74, k75 },     \
        { KC_NO, k82, k83, k84, k85 }  \
    }
