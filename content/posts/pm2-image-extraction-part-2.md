+++
date = '2025-05-21T23:02:19-04:00'
draft = false
title = 'Decoding and Decompressing PM2’s Background Images'
tags = ["DOS", "Retro Gaming", "Reverse Engineering"]
thumbnail = "img/20250521-pm2_gnd/mainoff2.gnd.bmp"
categories = ["PM2 Reverse Engineering"]
+++

So! This is it. After slacking off for a while, I think I’m ready to reverse engineer the Premier Manager 2 (PM2) image compression format for the background (`.gnd`) files. A year or so ago, I worked on the `.vga` files, so now it’s time to try decoding the `.gnd` files. I haven’t touched this in a while, so I’m not sure how far I got last time. Honestly figuring these type of thigns is lot more fun that playing the game. Without further ado, let’s start!

Judging by the filenames, the `.gnd` files are background images. The easiest way to begin is to find a way to reliably display a specific image in the game, inspect the file for patterns, and then modify it byte by byte to see the effects.

I’m doing this on my Mac, but you can use whatever OS you prefer. I’m using [DosBox-X](https://dosbox-x.com) as my DOS emulator.

## First Steps
First, here are all the `.gnd` files sorted by size so I can choose the smallest one to start with:

```bash
ls -lSh *.gnd
-rw-r--r--@ 1 nunoalves  staff    34K Dec 24  1996 credits.gnd
-rw-r--r--@ 1 nunoalves  staff    30K Dec 24  1996 seas2.gnd
-rw-r--r--@ 1 nunoalves  staff    26K Dec 24  1996 seas1.gnd
-rw-r--r--@ 1 nunoalves  staff    24K Dec 24  1996 titlepic.gnd
-rw-r--r--@ 1 nunoalves  staff    20K Dec 24  1996 seas3.gnd
-rw-r--r--@ 1 nunoalves  staff    18K Dec 24  1996 mainoff2.gnd
-rw-r--r--@ 1 nunoalves  staff    18K Dec 24  1996 validpi2.gnd
-rw-r--r--@ 1 nunoalves  staff    17K Dec 24  1996 result.gnd
-rw-r--r--@ 1 nunoalves  staff    16K Dec 24  1996 diskpic2.gnd
-rw-r--r--@ 1 nunoalves  staff    12K Dec 24  1996 sec2.gnd
-rw-r--r--@ 1 nunoalves  staff    12K Dec 24  1996 sponsor1.gnd
-rw-r--r--@ 1 nunoalves  staff    12K Dec 24  1996 sound.gnd
-rw-r--r--@ 1 nunoalves  staff   9.9K Dec 24  1996 report.gnd
-rw-r--r--@ 1 nunoalves  staff   9.6K Dec 24  1996 options2.gnd
-rw-r--r--@ 1 nunoalves  staff   9.3K Dec 24  1996 contract.gnd
-rw-r--r--@ 1 nunoalves  staff   6.5K Dec 24  1996 gndpane2.gnd
-rw-r--r--@ 1 nunoalves  staff   6.0K Dec 24  1996 gndside2.gnd
-rw-r--r--@ 1 nunoalves  staff   6.0K Dec 24  1996 gndgoal2.gnd
-rw-r--r--@ 1 nunoalves  staff   5.4K Dec 24  1996 padpic2.gnd
-rw-r--r--@ 1 nunoalves  staff   4.6K Dec 24  1996 tactic.gnd
-rw-r--r--@ 1 nunoalves  staff   4.2K Dec 24  1996 matchpic.gnd
-rw-r--r--@ 1 nunoalves  staff   2.7K Dec 24  1996 namespic.gnd
-rw-r--r--@ 1 nunoalves  staff   2.4K Dec 24  1996 anim.gnd
-rw-r--r--@ 1 nunoalves  staff   1.9K Dec 24  1996 monitor.gnd
-rw-r--r--@ 1 nunoalves  staff   1.6K Dec 24  1996 gndcove2.gnd
-rw-r--r--@ 1 nunoalves  staff   1.3K Dec 24  1996 fax.gnd
-rw-r--r--@ 1 nunoalves  staff   1.3K Dec 24  1996 sponsor2.gnd
````

So, `sponsor2.gnd` is the smallest, so it should be the easiest to understand and decode. To find out where it appears in-game, back it up and replace its contents with another file (for example, `sec2.gnd`):

```bash
mv sponsor2.gnd sponsor2.bak
cp sec2.gnd sponsor2.gnd
```

Weirdly, PM2 crashes whenever the sponsors window is clicked—suggesting a format mismatch. That crash was a godsend, because now I know `sponsor2.gnd` is rendered behind the sponsors icon on the main screen:
{{< figure src="/img/20250521-pm2_gnd/sec2.png" title="Copying sec2.gnd to sponsor2.gnd crashes PM2" >}}

As a baseline, I restore the original `sponsor2.gnd` and check how the sponsors menu looks:
{{< figure src="/img/20250521-pm2_gnd/sponsors2.png" title="Original sponsor2.gnd in-game" >}}

It turns out `sponsor2.gnd` is the cloud background. Next, let’s replace it with another file—say `diskpic2.gnd`:
{{< figure src="/img/20250521-pm2_gnd/diskpic2.png" title="diskpic2.gnd used as sponsor2.gnd; background changed successfully" >}}

It seems some background files crash PM2 when copied into `sponsor2.gnd`. Let’s see which ones crash the game and which don’t:

* **Crashes**:
	`credits.gnd`, `seas2.gnd`, `seas1.gnd`, `titlepic.gnd`, `seas3.gnd`, `validpi2.gnd`, `sec2.gnd`, `sponsor1.gnd`, `sound.gnd`, `report.gnd`, `options2.gnd`, `contract.gnd`, `gndpane2.gnd`, `gndside2.gnd`, `gndgoal2.gnd`, `tactic.gnd`, `namespic.gnd`

* **OK**:
	`mainoff2.gnd`, `result.gnd`, `diskpic2.gnd`, `phonpic2.gnd`, `padpic2.gnd`, `matchpic.gnd`, `anim.gnd`, `monitor.gnd`, `gndcove2.gnd`, `fax.gnd`

It looks like certain `.gnd` files are decoded differently—dubious! In any case, since `sec2.gnd` appears in the secretary window, let’s apply the same trick and see if the rest of the files can be decoded when their contents are copied into `sec2.gnd`.
* **OK**:
	`seas2.gnd`, `seas1.gnd`, `seas3.gnd`, `validpi2.gnd`, `sponsor1.gnd `, `sound.gnd`, `report.gnd`, `options2.gnd`, `gndpane2.gnd`, `gndside2.gnd`, `gndgoal2.gnd`, `tactic.gnd`, `namespic.gnd`
* **OK (...But Odd Colors)**:
	`credits.gnd`, `titlepic.gnd`, `contract.gnd`

{{< figure src="/img/20250521-pm2_gnd/sec2a.png" title="Baseline sec2.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/seas2.png" title="seas2.gnd used as sec2.gnd; background changed successfully" >}}

I strongly suspect the odd colors are caused by decoding with a different palette. This is promising—there are two distinct decoding routines for the background images. One routine uses two palettes. All good!

## Entropy Analysis
Using a hex editor, I took a quick peek at the `.gnd` files and, unlike the `.vga` files, they appear to be compressed. To confirm this, I measured the files’ entropy with a tool like [binwalk](https://github.com/ReFirmLabs/binwalk). Binwalk calculates Shannon entropy over fixed-size windows (1024 bytes each), giving a snapshot of how “random” each region is. An entropy of 0 bits/byte means all bytes are identical, whereas 8 bits/byte indicates perfectly random data. Higher entropy corresponds to higher information content. I like to think of it as how surprised you are by the next byte: if you see many consecutive identical bytes, each repeat is unsurprising—and thus low entropy.

The binwalk algorithm is straightforward:

1. Read 1024 bytes (offset 0–1023).  
2. Count the occurrences of each byte (build a 256-element histogram).  
3. Divide each byte count by 1024 to calculate its frequency.  
4. Compute the [entropy](https://en.wikipedia.org/wiki/Entropy_(information_theory)) for this window.  
5. Move on to the next 1024 bytes (1024–2047) and repeat.

Running the following commands will log the raw entropy data and generate entropy graphs for each file type.

```bash
binwalk sponsors.vga --entropy --log sponsors2.txt
binwalk sec2.gnd     --entropy --log sec2.txt
````

In the images below, the Y-axis (0 – 8 bits/byte) shows the entropy for each 1024-byte block. `sponsors.vga` never exceeds about 3.5 bits/byte, whereas `sec2.gnd` sits around 6.3 bits/byte—implying a high degree of randomness and suggesting a pretty good compression mechanism.

{{< figure src="/img/20250521-pm2_gnd/entropy-sec2_gnd.png" title="sec2.gnd has high entropy, suggesting compression" >}}

{{< figure src="/img/20250521-pm2_gnd/entropy-sponsors_vga.png" title="sponsors.vga has low entropy, suggesting no compression" >}}

## Displaying Palette Data
I have a hunch I'll spend a lot of time examining the raw compressed files alongside their rendered images. The first step is to map each pixel byte (0x00–0xFF) to its corresponding RGB color. Since I'm a visual thinker, it's most helpful to have a full color matrix at hand. Here’s a small [Python script](https://github.com/nunoalves/PM2_Legacy/blob/dcfd3712b4d847e2f3a52ea28f6856f5915293ec/tools/printPalette.py#L1) that generates exactly that matrix.

To run it locally:

```bash
python3 tools/printPalette.py ../assets/paldata.vga paldata_16.bmp --base 16
```

{{< figure src="/img/20250521-pm2_gnd/paldata_16.bmp" title="Main game palette colors, extracted from paldata.vga" >}}

## First Steps
I am still unsure what the format of this compressed file is, but juding from the time this game was made (~1992), I strongly suspect this compressed file is a either a custom variant of RLE or LZSS algorithm. Most likely is a combo of box, so I’ll use that as my starting point.

To make my life easier, I’ll focus only on the smallest files that use the same compression scheme: `fax.gnd`, `gndcove2.gnd`, and `sponsor2.gnd`.

Using a hex editor (e.g. HexFiend), I compare the first hundred or so bytes of each file, looking for patterns.  
{{< figure src="/img/20250521-pm2_gnd/firstBytesComparison.png" title="Comparing the first bytes of each file" >}}

Normally, LZSS-compressed data begins with header metadata. The first two bytes of both `gndcove2.gnd` and `sponsor2.gnd` are identical. I’m not yet sure what they represent, but I suspect they relate to the image size, since both files display at the same dimensions in-game.

Next, I’ll analyze the `sponsor2.gnd` image. I also assume it renders top-to-bottom. Looking at the pixels, the initial pattern is “GREY WHITE WHITE GREY WHITE WHITE GREY WHITE WHITE.”  
{{< figure src="/img/20250521-pm2_gnd/sponsors2_zoomed.png" title="Zoomed-in view of the original sponsor2.gnd file." >}}

The first bytes are `0x03 0x54 0x3A 0x3A 0x81`. According to the palette matrix above, `0x3A` is white and `0x81` is blue. If I change the first `0x3A` to `0x35`, some white pixels should turn red.  
{{< figure src="/img/20250521-pm2_gnd/sponsors2-first_3A_replaced_with_35.png" title="Replacing the first 0x3A with 0x35 in sponsor2.gnd results in the first white pixel (and many downstream pixels) turning red." >}}

After a few more trials, errors, and investigations, here’s what I’ve discovered:

| Byte | Original (HEX) value | Purpose                         |
| ---- | -------------------- | ------------------------------- |
| 0    | `03`                 | maybe next 3 bytes are literal  |
| 1    | `54`                 | pixel #1 (grey)                 |
| 2    | `3A`                 | pixel #2 (white)                |
| 3    | `3A`                 | pixel #3 (white)                |
| 4    | `81 0A`              | maybe look back 3, copy 3       |
| 6    | `C8 00`              | maybe look back 6, copy 6       |
| 8    | `C8 06`              | maybe look back 12, copy 8      |
| 10   | `03`                 | maybe next 3 bytes are literal  |
| 11   | `EA`                 | pixel #21 (blue)                |
| 12   | `54`                 | pixel #22 (grey)                |
| 13   | `EA`                 | pixel #23 (blue)                |

It appears that the first byte specifies how many subsequent bytes are literal values. Bytes 1–3 are  literal pixel values, followed by a sequence of back-reference bytes and then more literals. My hypothesis of a custom RLE compression start gaining traction.

Below is a cleaner, more concise version of the post, ready to drop into a Hugo `*.md` file.  I fixed typos, tightened wording, and used fenced code-blocks so the hex snippets render nicely.

## Decoding the `.gnd` Files

After some byte-tweaking I reached four conclusions about the compression format:

1. Every byte in the stream is an **opcode** (command) or its argument.
2. The **first** byte of a file is always an opcode.
3. Opcodes may have 0, 1, or 2 argument bytes.
4. “Copy” opcodes reference **previously decoded bytes** (already-drawn
   pixels); they never look ahead.

My workflow was simple:

1. Pick a `.gnd` file, spot patterns in the raw bytes vs. on-screen pixels.  
2. Guess the meaning of an opcode.  
3. Implement that guess in Python.  
4. Re-decode the image—if something looked wrong I knew either my guess or my
   code was off.

Below are a few annotated byte traces extracted from the various files I used to get the ball rolling...

---

### Literal & Repeat Samples

```text
mainoff2.gnd
43 3B 01 5F 44 3A 00
    -> 5x orange(3B) 1x green(5F) 7x white(3A)

result.gnd
61 1B 35 00
    -> row-fill: 319x red(35) (one full 320-pixel row minus the last pixel)

phonpic2.gnd
60 02 35 00
    -> 38x red(35)
````

### Small “Copy” Sequences

```text
padpic2.gnd
04 3B 5F 3A 35 00
    -> orange, green, white, red

04 3B 5F 3A 35 43 C2 00
    -> above + 6x brown(C2)

04 3B 5F 3A 35 43 C2 85 01 C0 00
    -> above + red + brown + light-brown(C0)
```

### Long Repeat & Copy Mix

```text
matchpic.gnd
63 AD 35 00
    -> about 3.5 rows of red(35)

63 AD 35 02 3A 3A 00
    -> above + 2x white(3A)
```

### Experimenting With “Fill” Opcodes

Replacing the entire file with a single opcode trio and you get predictable spans:

```text
40 35 00  -> 3x red
47 35 00  -> 10x red
4E 35 00  -> 17x red
5F 35 00  -> 34x red
60 1C 35 00 -> 64x red
61 1C 35 00 -> 320x red (full row)
```

---

### Complete **`.gnd`** Opcode Reference

| Opcode value(s) | Argument bytes | Mnemonic<sup>*</sup>        | Action (pseudocode)                                                                                                                                         | Typical effect                                          |                                                                |
| --------------- | -------------- | --------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------- | -------------------------------------------------------------- |
| `00`            | —              | **END**                     | `stop()`                                                                                                                                                    | Terminates the stream                                   |                                                                |
| `01–1F`         | *N* literals   | **LIT N**                   | `copy(src[pos+1 : pos+1+N])`                                                                                                                                | Copy the next 1-31 raw bytes                            |                                                                |
| `40–5F`         | `vv`           | **RPT m×vv**                | `m = (opcode & 0x3F) + 3` <br> `repeat(vv, m)`                                                                                                              | Short run-length repeat (3-34 pixels)                   |                                                                |
| `60–7F`         | `xx vv`        | **RPT n×vv**                | `n = ((opcode & 0x1F)<<8) + xx + 36` <br> `repeat(vv, n)`                                                                                                   | Long repeat (≥ 36). Values near 320 give full-row fills |                                                                |
| `80–9F`         | `yy`           | **CPY2 off=d**              | `d = yy + 2` <br> `copy_back(d, 2)`                                                                                                                         | Copy 2 pixels from up to 257 bytes back                 |                                                                |
| `A0–BF`         | `yy`           | **CPY3 off=d**              | `d = yy + 3` <br> `copy_back(d, 3)`                                                                                                                         | Copy 3 pixels from up to 258 bytes back                 |                                                                |
| `C0–FF`         | `yy`           | **CPYk off=d**              | `grp = (opcode>>4) − 0xC`  <br> base = 4,8,12,16 <br> `extra = (opcode>>2)&3`  <br> *k = base+extra* (4-19) <br> `window = opcode & 0x03` <br> `offset = (window<<8)` \| `yy` (0-1023) <br> `d = offset + k` <br> `copy_back(d, k)` | General copy-back (length 4-19, distance ≥ length, max ≈ 1042) |

<sup>* Mnemonic legend</sup>

* **LIT N**    copy *N* literal bytes
* **RPT m×vv**   repeat byte `vv` *m* times
* **CPYk off=d** copy *k* bytes from `d` positions back in the output buffer


## The Decoder Script

I wrote a small Python tool,
[`gndToBmp.py`](https://github.com/nunoalves/PM2_Legacy/blob/e74f7ac9e7a0db8c0031fc2341472a7e0d3e3cab/tools/gndToBmp.py),
that:

* walks the stream opcode-by-opcode,
* shows a live log of each operation,
* writes an updated BMP after every opcode when `--step` is enabled.

Run it like this:

```bash
python3 gndToBmp.py ~/dosbox/pm2/gndcove2.gnd \
     ../assets/paldata.vga           \
     --scale 5                       \
     --step
```

The options mean:

* **`--scale 5`** – enlarge the output BMP 5×.
* **`--step`**   – pause after every opcode, write
  `step_0001.bmp`, `step_0002.bmp`, … alongside the log.

{{<figure src="/img/20250521-pm2_gnd/step_0276.bmp"
title="Bitmap after 276 decoded opcodes">}}

{{<figure src="/img/20250521-pm2_gnd/step_0561.bmp" title="Bitmap after 561 decoded opcodes">}}

Here is the main terminal window showing the decoding for each instruction, where:

* **`LIT N`** – copy *N* literal bytes that follow  
* **`RPTm×VV`** – repeat byte `0xVV` *m* times  
* **`CPYk off=D`** – copy *k* bytes from *D* positions back in the history  
  * `CPY2` opcodes live in **80–9F**  
  * `CPY3` opcodes live in **A0–BF**  
  * `CPY4–CPY19` opcodes live in **C0–FF**  

{{<figure src="/img/20250521-pm2_gnd/trace_command.png"
title="Live trace: frame #, file offset, raw bytes, and decoded meaning">}}

## Decoded Images
Here are the results of running the decoding tool [`gndToBmp.py`](https://github.com/nunoalves/PM2_Legacy/blob/e74f7ac9e7a0db8c0031fc2341472a7e0d3e3cab/tools/gndToBmp.py), on the various images.

{{< figure src="/img/20250521-pm2_gnd/mainoff2.gnd.bmp" title="mainoff2.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/result.gnd.bmp" title="result.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/diskpic2.gnd.bmp" title="diskpic2.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/phonpic2.gnd.bmp" title="phonpic2.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/padpic2.gnd.bmp" title="padpic2.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/matchpic.gnd.bmp" title="matchpic.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/anim.gnd.bmp" title="anim.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/monitor.gnd.bmp" title="monitor.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/gndcove2.gnd.bmp" title="gndcove2.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/sponsor2.gnd.bmp" title="sponsor2.gnd" >}}

{{< figure src="/img/20250521-pm2_gnd/fax.gnd.bmp" title="fax.gnd" >}}

## Final Thoughts
Figuring out a compression protocol without reverse-engineering the executable was actually a lot more fun than playing the game. The protocol itself feels tacked together. Also, different images apparently need a different decoding protocol (which I’ll check out another time). I’m a little confused why they made a custom RLE implementation with strange offsets, rather than using a canned LZSS implementation that’s been around since 1982 (or one of its later variants, like LZW). Anyway, it seems [others](https://moddingwiki.shikadi.net/wiki/RLE_Compression#Code) have done similar things, so it must be okay. Maybe in one of my next posts I’ll compare this with other early-1990s compression schemes—to see what the Premier Manager 2 team were drinking :)
