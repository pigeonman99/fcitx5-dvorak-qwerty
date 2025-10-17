/*
 * SPDX-FileCopyrightText: 2021~2021 CSSlayer <wengxt@gmail.com>
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "dq.h"
#include <fcitx/inputcontext.h>
#include <fcitx-utils/keysym.h>

DQEngine::DQEngine() {
    qwertyToDvorak = {
        // Top row
        {FcitxKey_q, "'"},
        {FcitxKey_w, ","},
        {FcitxKey_e, "."},
        {FcitxKey_r, "p"},
        {FcitxKey_t, "y"},
        {FcitxKey_y, "f"},
        {FcitxKey_u, "g"},
        {FcitxKey_i, "c"},
        {FcitxKey_o, "r"},
        {FcitxKey_p, "l"},
        {FcitxKey_bracketleft, "/"},
        {FcitxKey_bracketright, "="},

        // Middle row
        {FcitxKey_a, "a"},
        {FcitxKey_s, "o"},
        {FcitxKey_d, "e"},
        {FcitxKey_f, "u"},
        {FcitxKey_g, "i"},
        {FcitxKey_h, "d"},
        {FcitxKey_j, "h"},
        {FcitxKey_k, "t"},
        {FcitxKey_l, "n"},
        {FcitxKey_semicolon, "s"},
        {FcitxKey_apostrophe, "-"},

        // Bottom row
        {FcitxKey_z, ";"},
        {FcitxKey_x, "q"},
        {FcitxKey_c, "j"},
        {FcitxKey_v, "k"},
        {FcitxKey_b, "x"},
        {FcitxKey_n, "b"},
        {FcitxKey_m, "m"},
        {FcitxKey_comma, "w"},
        {FcitxKey_period, "v"},
        {FcitxKey_slash, "z"},

        // Uppercase letters
        // Top row
        {FcitxKey_Q, "\""},
        {FcitxKey_W, "<"},
        {FcitxKey_E, ">"},
        {FcitxKey_R, "P"},
        {FcitxKey_T, "Y"},
        {FcitxKey_Y, "F"},
        {FcitxKey_U, "G"},
        {FcitxKey_I, "C"},
        {FcitxKey_O, "R"},
        {FcitxKey_P, "L"},
        {FcitxKey_braceleft, "?"},
        {FcitxKey_braceright, "+"},

        // Middle row
        {FcitxKey_A, "A"},
        {FcitxKey_S, "O"},
        {FcitxKey_D, "E"},
        {FcitxKey_F, "U"},
        {FcitxKey_G, "I"},
        {FcitxKey_H, "D"},
        {FcitxKey_J, "H"},
        {FcitxKey_K, "T"},
        {FcitxKey_L, "N"},
        {FcitxKey_colon, "S"},
        {FcitxKey_quotedbl, "_"},

        // Bottom row
        {FcitxKey_Z, ":"},
        {FcitxKey_X, "Q"},
        {FcitxKey_C, "J"},
        {FcitxKey_V, "K"},
        {FcitxKey_B, "X"},
        {FcitxKey_N, "B"},
        {FcitxKey_M, "M"},
        {FcitxKey_less, "W"},
        {FcitxKey_greater, "V"},
        {FcitxKey_question, "Z"}
    };
}

void DQEngine::keyEvent(const fcitx::InputMethodEntry& entry, fcitx::KeyEvent& keyEvent)
{
    FCITX_UNUSED(entry);
    FCITX_INFO() << keyEvent.key() << " isRelease=" << keyEvent.isRelease();

    if (!keyEvent.isRelease() && keyEvent.key().states() == 0) {
        auto it = qwertyToDvorak.find(keyEvent.key().sym());
        if (it != qwertyToDvorak.end()) {
            keyEvent.accept();
            keyEvent.inputContext()->commitString(it->second);
            return;
        }
    }
}

FCITX_ADDON_FACTORY(DQEngineFactory);