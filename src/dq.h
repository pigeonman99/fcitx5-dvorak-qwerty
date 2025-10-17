/*
 * SPDX-FileCopyrightText: 2021~2021 CSSlayer <wengxt@gmail.com>
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef _FCITX5_DQ_DQ_H_
#define _FCITX5_DQ_DQ_H_

#include <fcitx/inputmethodengine.h>
#include <fcitx/addonfactory.h>
#include <unordered_map>

class DQEngine : public fcitx::InputMethodEngineV2 {
public:
    DQEngine();
    void keyEvent(const fcitx::InputMethodEntry & entry, fcitx::KeyEvent & keyEvent) override;

private:
    std::unordered_map<uint32_t, const char*> qwertyToDvorak;
};

class DQEngineFactory : public fcitx::AddonFactory {
    fcitx::AddonInstance * create(fcitx::AddonManager * manager) override {
        FCITX_UNUSED(manager);
        return new DQEngine;
    }
};

#endif // _FCITX5_DQ_DQ_H_