# JellyTitan Junco Keymap
![jellytitan](https://i.imgur.com/JqGPWCn.png)

This keymap is derived from Ergodox layouts and is adapted for the [Junco](https://github.com/daneski13/Junco). 
It is notable for it's semi-complex programming examples that include the use of rotary encoders.

Plenty of useful examples:
* Advanced knob programming! (Three-layer usage + clicks)
* Macros! (Fancy key combos tied to the rotary encoders)
* Tap Dance! (Double tap your '5' key for 'Enter')
* Dynamic Tapping term! (Dial in the double tap speed)

The qwerty key layout is my adaptation of the Ergodox defaults. 
If this is your first split keyboard, you probably want a different key layout. 

Flashing example for this keyboard:

```bash
# For flashing the left half...
make junco:jellytitan:uf2-split-left
# or the qmk cli equivalent:
qmk flash -kb junco --keymap jellytitan -bl uf2-split-left

# For flashing the right half...
make junco:jellytitan:uf2-split-right
# or the qmk cli equivalent:
qmk flash -kb junco --keymap jellytitan -bl uf2-split-right
```
