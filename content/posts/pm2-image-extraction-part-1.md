+++
title = "Extracting Assets From Premier Manager 2"
date  = "2024-04-20T14:30:00-04:00"
draft = false
tags  = ["DOS", "Retro Gaming", "Reverse Engineering"]
thumbnail = "img/20240420-pm2_assets/thumb.bmp"
+++

About once every five years I fire up *[Premier Manager 2](https://en.wikipedia.org/wiki/Premier_Manager_2)* — THE soccer management game before *[Championship Manager](https://en.wikipedia.org/wiki/Championship_Manager_93/94)* monopolised the genre. (These days, you can even play [PM2 in your browser](https://archive.org/details/msdos_Premier_Manager_2_1993).)

Before starting to play, this time I noticed an interesting mix of files in the root directory — thingslike `contract.gnd`, `icons.vga`, `anim.bin`, `goal.voc`, and others—and wondered how hard it would be to decode them with modern tooling. Surely the `.gnd` and `.vga` files were graphic assets, the `.voc` files audio, and so on. A little reverse‑engineering later, here’s what I found about the image formats...

---

## The PM2 `.vga` Format

Every PM2 graphic needs two files:

1. **Image file** (e.g. `icons.vga`, `font16c.vga`) – stores pixel indices.
2. **Palette file** (`paldata.vga` for in‑game screens, `paltitle.vga` for the title screen) – stores the actual colours.

The PM2 palette is just a basic look‑up table: 256 entries x 3 bytes (red, green, blue) = 768 bytes that follow a 0x100‑byte header. Each pixel in the image is an index (0‑255) into that palette table, keeping files tiny and guaranteeing that every sprite, font, and icon shares the exact same colour set.

Why only 256 colours? Classic DOS VGA modes (320 × 200, 8‑bit), such as this masterpiece, were limited to a 256‑entry palette. SVGA later raised the bar on resolution and, eventually, colour depth, but PM2 shipped pretty much as SVGA was getting started.

### File layout

```
0x000–0x0FF   File header (256 bytes)
0x100–0x3FF   Palette data (only in palette files: 256 × RGB)
0x400–EOF     Image blocks
```

Each *image block* starts with an 8‑byte header:

| Offset | Size (Bytes) | Purpose           |
| -----: | ---: | ----------------- |
|      0 |  4   | unused / reserved |
|      4 |  2   | height (`y_size`) |
|      6 |  2   | width (`x_size`)  |

Pixel data immediately follows and is exactly `width x height` bytes. Because of that regularity, you can iterate through a file like so:

```python
block_size = x_size * y_size + 8
num_images = len(raw_data) // block_size
```

---

## Tool 1 - Batch Image Extractor
- **[verifyAssets.py](https://github.com/nunoalves/PM2_Legacy/blob/c0e808c4ee9800a2d2864b18bfc1e6254aa5d42f/tools/verifyAssets.py#L1)**
- **[vgaToBmp.py](https://github.com/nunoalves/PM2_Legacy/blob/c0e808c4ee9800a2d2864b18bfc1e6254aa5d42f/tools/vgaToBmp.py#L1)**

I wrote two small Python scripts that validate all assets, walk through a `.vga` file, pulls out each bitmap, and saves it as a BMP. Grab the PM2 game files (the easiest source is [My Abandonware](https://www.myabandonware.com/game/premier-manager-2-1zx#download)), drop them in an `assets/` folder, then run:

```bash
python3 verifyAssets.py     # validates file hashes
python3 vgaToBmp.py         # dumps every icon/font/sprite to BMP
```

> **...But I don't want to run your janky script.** 

Fine... Here are the extracted assets images:

{{< figure src="/img/20240420-pm2_assets/fax_merged.bmp"      title="Fax screen (fax_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/font16c_merged.bmp"  title="Font16c glyphs (font16c_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/font55_merged.bmp"   title="Font55 glyphs (font55_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/font57_merged.bmp"   title="Font57 glyphs (font57_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/font57b_merged.bmp"  title="Font57b glyphs (font57b_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/font77_merged.bmp"   title="Font77 glyphs (font77_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/font77b_merged.bmp"  title="Font77b glyphs (font77b_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/font77c_merged.bmp"  title="Font77c glyphs (font77c_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/fontf9_merged.bmp"   title="FontF9 glyphs (fontf9_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/gndscore_merged.bmp" title="Score background (gndscore_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/gndseats_merged.bmp" title="Stadium seats (gndseats_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/groundix_merged.bmp" title="Ground index (groundix_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/icons_merged.bmp"    title="UI icons (icons_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/impslbar_merged.bmp" title="Impulse bar (impslbar_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/matball_merged.bmp"  title="Match ball icon (matball_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/matbtn_merged.bmp"   title="Match buttons (matbtn_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/matspd_merged.bmp"   title="Match speed bar (matspd_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/phone2_merged.bmp"   title="Phone UI 1 (phone2_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/phonem_merged.bmp"   title="Phone UI 2 (phonem_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/pitch_merged.bmp"    title="Pitch sprites (pitch_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/pitchbit_merged.bmp" title="Pitch bitmap (pitchbit_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/posgraph_merged.bmp" title="Position graph (posgraph_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/report_merged.bmp"   title="Report screen (report_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/result_merged.bmp"   title="Result screen (result_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/sec2_merged.bmp"     title="Security screen 2 (sec2_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/sh_merged.bmp"       title="Shareholders screen (sh_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/sponsors_merged.bmp" title="Sponsors screen (sponsors_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/ticket_merged.bmp"   title="Ticket window (ticket_merged.vga)" >}}

{{< figure src="/img/20240420-pm2_assets/validbtn_merged.bmp" title="Validation buttons (validbtn_merged.vga)" >}}

---

## Tool 2 - Dynamic Font Display
- **[dynamicFontDisplay.py](https://github.com/nunoalves/PM2_Legacy/blob/c0e808c4ee9800a2d2864b18bfc1e6254aa5d42f/tools/dynamicFontDisplay.py#L1)**

With the fonts extracted, why not type in glorious mid‑90 s style?
`dynamicFontDisplay.py` is a quick Pygame demo that does exactly that:

```bash
python3 dynamicFontDisplay.py assets/font16c.vga assets/paldata.vga --scale 4
```

Where `--scale` enlarges each glyph by an integer factor. Here’s a sample output:

![Dynamic font demo](/img/20240420-pm2_assets/dynamicText.png)

---

## Next Steps ...

The image background `.gnd` files are tougher: they appear to be compressed with a custom Lempel‑Ziv–Huffman variant. I’m pretty sure I’ll have to dive into the main executable to see how its compressed. Next time.