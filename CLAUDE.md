# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What This Repo Is

A QMK userspace repository — keymaps and keyboard configs maintained outside the main QMK firmware source tree. This repo does not contain QMK firmware itself; it only contains the user-specific overlays that get compiled against it.

Active build targets (defined in [qmk.json](qmk.json)):
- `junco/rev1` → keymap `jellytitan`
- `keebio/iris/rev6` → keymap `two_knob`
- `ergodonk_zero` → keymap `jellytitan`
- `ergodonk_zero` → keymap `via`

## Commands

All commands assume QMK CLI is installed and `qmk setup` has been run (or you are inside the devcontainer).

**Build all targets in qmk.json:**
```sh
qmk userspace-compile
```

**Build a single keyboard/keymap:**
```sh
qmk compile -kb ergodonk_zero -km jellytitan
qmk compile -kb junco/rev1 -km jellytitan
qmk compile -kb keebio/iris/rev6 -km two_knob
```

**Flash firmware to a keyboard:**
```sh
qmk flash -kb ergodonk_zero -km jellytitan
```

**Lint a keymap (runs clang-format and QMK linter):**
```sh
qmk lint -kb ergodonk_zero -km jellytitan
```

**Format C files (uses [.clang-format](.clang-format) — Google style, 4-space indent, 1000 col limit):**
```sh
clang-format -i keyboards/ergodonk_zero/keymaps/jellytitan/keymap.c
```

## Architecture

### Keymap file structure

Each keymap lives at `keyboards/<kb>/keymaps/<name>/` and may contain:
- `keymap.c` — layer definitions, custom keycodes, tap dance, encoder maps, `process_record_user`
- `config.h` — per-keymap overrides (tapping term, RGB, split handedness, mouse accel)
- `rules.mk` — feature flags (`TAP_DANCE_ENABLE`, `VIA_ENABLE`, `ENCODER_MAP_ENABLE`, `POINTING_DEVICE_ENABLE`)
- `readme.md` — optional documentation

The `layouts/` and `users/` directories are present but currently empty.

### QMK userspace build system

The [Makefile](Makefile) is a thin pass-through to the QMK firmware Makefile with `QMK_USERSPACE` pointed at this directory. The real build logic lives in QMK firmware itself. [qmk.json](qmk.json) at the root registers this directory as a userspace and lists all targets that `qmk userspace-compile` will build.

### GitHub Actions

`.github/workflows/build_binaries.yaml` uses QMK's official reusable workflows to build and publish firmware to GitHub Releases on every push. The QMK firmware source repo and branch can be overridden via workflow inputs (currently tracking `qmk/qmk_firmware@master`).

### Common patterns across keymaps

- **Layer scheme**: QWERTY base → LOWER / RAISE (momentary) → ADJUST (tri-layer via `update_tri_layer`)
- **Tap dance**: Used for keys that do different things on single vs. double tap (e.g., Esc toggles a layer on double-tap)
- **Encoder maps**: Layer-aware via `ENCODER_MAP_ENABLE`; each layer defines separate CW/CCW actions
- **Mac-specific macros**: Window snapping shortcuts target the Magnet app (`Cmd+Opt+Ctrl+<arrow>`)
- **Custom keycodes**: Defined as enums starting at `SAFE_RANGE`; handled in `process_record_user`

### Devcontainer

The [.devcontainer/](.devcontainer/) setup uses the official `ghcr.io/qmk/qmk_cli` image. On `postCreateCommand` it runs `qmk setup` and clones QMK firmware into the container. Use this to get a consistent build environment without installing QMK locally.

## Adding a New Keyboard/Keymap

1. Create `keyboards/<kb>/keymaps/<name>/` with at minimum `keymap.c` and `rules.mk`
2. Add the target to [qmk.json](qmk.json) under `"targets"`
3. Test with `qmk compile -kb <kb> -km <name>`
