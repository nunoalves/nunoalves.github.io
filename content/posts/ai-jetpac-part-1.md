+++
date = '2025-05-09T21:51:55-04:00'
draft = true
title = 'AI Jetpac, Part 1'
+++

So the other day I found myself firing up an emulator to play some of the ’80s [ZX Spectrum](https://en.wikipedia.org/wiki/ZX_Spectrum) games that were a staple of my childhood. I ran through the classics—**[Manic Miner](https://en.wikipedia.org/wiki/Manic_Miner)**, **[Skool Daze](https://en.wikipedia.org/wiki/Skool_Daze)**, **[Rambo](https://worldofspectrum.net/item/0004010/)**, **[Bruce Lee](https://worldofspectrum.net/item/0000718/)**—but there’s always one that stands out: **[Jetpac](https://en.wikipedia.org/wiki/Jetpac)**.  Masterpiece. You’re an 80's astronaut, lazering aliens while scavenging fuel that falls from the sky, using it to refill your ship so it can take you to a another planet that looks the same... Where did that fuel come from? Why does Jetman teleport to the opposite edge when he hits the screen border? Mysteries yet unsolved. At age five, I was rubbish at Jetpac; decades later I still am. Unable to reach level 4, I am bested by a game that fits in 48 KB of RAM.

> **If only there were a way to play better...**

The next day—during my lunch break—I stumbled once again on Petter Ögren’s [behavior-tree introduction videos](https://www.youtube.com/watch?v=KeShMInMjro&list=PLFQdM4LOGDr_vYJuo8YTRcmv3FrwczdKg). In a nutshell, a behavior tree is just a way to decide what to do next. Let’s say you have a little video-game character (an agent), and there are many "simple" actions they can perform at any moment (e.g. move left, jump, dodge, shoot, etc.). By deciding which action to perform next, you can give that character surprisingly complex and intelligent behavior—run then dodge when barely close to an enemy, and shoot sideways while moving backwards and facing down. The neat thing about behavior trees is that the next action depends on the entire state of the world, not on the task currently being performed (as with finite-state machines). Super neat. Seemed like a good idea to give Jetman some intelligence and let him play himself. Hobby project... Not sure when I’ll be done—it may take a while—but there’s no better place to begin than at the beginning.

---

## First Steps

1. **Hook into ZEsarUX’s remote protocol**  
   To give Jetman some AI, I need to control it programmatically (press movement buttons) and read the game state (e.g. where Jetman and the enemies are). The easiest way is to run Jetpac under ZEsarUX 12.0 with `--enable-remoteprotocol`. That opens a TCP socket so you can issue text commands (via telnet) directly to the emulator—things like `read-memory` and `send-keys-event` to inspect memory and press keys.

2. **Reverse-engineer the game state**  
   From [Phillipe Eaton’s disassembly](https://phillipeaton.github.io/jetpac-disassembly/), I extracted the RAM addresses that store:
   * Jetman’s X/Y position, speed, lives, and level  
   * Six alien slots’ X/Y coordinates and speeds

3. **Python code**  
   Python makes it quick and dirty to wire this up. My script opens the socket, sends the keys to start the game, polls the game state every 200 ms, and passes that info into my AI controller.

4. **Janky AI controller**  
   My initial AI is as janky as it gets. If the closest alien is within 40 pixels, fire the laser (direction doesn’t matter). Otherwise, always move away from enemies—ignoring platforms, wrap-around edges, fuel pickups, and basically everything else.

   	{{< figure 
       	src="/img/jetpac_ai_20250509.png" 
       	caption="AI controller on level 1" 
	>}}


---

## Getting It to Work

Check out [this repo](https://github.com/nunoalves/ai-jetpac/tree/043e3c445ca882f0d96c01f23e84f63f522904f9) for the complete code.

1. Edit the `runme.sh` or `runme.bat` script to point to your ZEsarUX emulator and the `Jetpac.tzx` file.  
2. Run the shell or batch script.  
3. In a parallel window, run:

   ```bash
   python main.py
	```

In `main.py`, you can toggle specific modes by setting these flags:

* `ENABLE_WATCH` — prints Jetman’s and all aliens’ positions and speeds.
* `ENABLE_AI_CONTROL` — enables the janky AI controller.
* `ENABLE_GAME_OVER_EXIT` — exits the script when the game is over.

With ZEsarUX’s remote protocol, only two commands are needed:

* **`read-memory <addr> 1`** — read a single byte from RAM.
* **`send-keys-event <code> <0|1>`** — press or release a Spectrum key.

All the RAM addresses and key codes live in [jetpac\_game\_state.py](https://github.com/nunoalves/ai-jetpac/blob/043e3c445ca882f0d96c01f23e84f63f522904f9/jetpac_game_state.py).

