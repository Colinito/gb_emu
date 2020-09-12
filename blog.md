# 2019-11-17

## Introduction
After a lot of sitting around, I decided to finally start work on my GameBoy
Color emulator. I have never written an emulator before, but I believe it is the
ultimate Computer Engineering software challenge and I want to dive right into
it. This has been a dream of mine for quite a while, even pre-dating my ability
to program. But after a few years, I feel confident enough to make my first
attempt. 

In this blog, I'll try to record everything I did, my thoughts, my
debugging process, my design choices, my frustrations, and my success (if any).
But let's be optimistic! 

## Why GameBoy Color?
When you search "how to write an emulator" or "first emulator project" online,
you will find StackOverflow answers and forum posts telling aspiring emulator
developers to start with a Chip-8 emulator. Most people won't even have heard
what this is. In fact, it's not an actual piece of hardware, but language.
Writing a Chip-8 "emulator" is really about writing a Chip-8 _interpreter_.

Yet, emulation is about replicating the functionality of another _hardware_
platform in software. I've already written a minimal Lisp interpreter.

I chose the GameBoy Color for a few reasons:
	1. _It's familiar_ - I grew up playing GameBoy games. This is a console
	I actually want to play. While there are excellent resources for writing
	an NES emulator, I don't have much nostalgia for that console.
	2. _It's simple_ - The GameBoy Color has simple hardware. It has a low-
	resolution screen and I've heard its graphics chip is not difficult to
	work with.

## Resources
Before I wrote any emulator code, I researched writing software for the GameBoy
Color so I could understand it from a programmer's POV. 

[GBDK](https://sourceforge.net/projects/gbdk/) is a c compiler that I hope to 
use it to quickly write simple test programs.

[mGBA](https://github.com/mgba-emu/mgba) is a GameBoy, GameBoy Color, and
GameBoy Advance emulator. I will use it as a testing/debugging tool.

Vertical blanking
http://zalods.blogspot.com/2016/07/game-boy-development-tips-and-tricks-ii.html

