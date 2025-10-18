# fcitx5-dvorak-qwerty
## Dvorak-qwerty Keyboard Layout for fcitx5
This is a dvorak-qwerty keyboard layout for fcitx5. When this input method is selected, you can type in Dvorak layout, but switches back to Qwerty layout when any of the modifier keys are pressed.

This fcitx5 plugin is built by following fcitx5's [developer documentation](https://fcitx-im.org/wiki/Develop_an_simple_input_method).

## Installation
To build and install this plugin in your fcitx5 installation, do this:
```
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug
make
sudo make install # or sudo ninja install
```
After that, restart your fcitx5. Then go to "Configure" page. You should see the dvorak-qwerty input method now becomes available. Add that to your current input method to start using it. Make sure your default system keyboard layout is Qwerty (English - US).
