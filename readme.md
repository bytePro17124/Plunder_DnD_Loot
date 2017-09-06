# Plunder


*A 5e Dungeon Master Helper Program*

<img src="plunder_screenshot_main_menu.png" height="180px" align="right">

* Generates Piles of Treasure in One Click (DM Guide Hoard Loot)
* Generates Spellbooks and Scrolls (Custom)
* Save results to a text file.
* Hours of game time saved!

#### get to lootin' (build instructions - linux)

1. ````git clone https://github.com/bytePro17124/Plunder.git```` downloads this program
2. ````cd plunder```` moves to directory
3. ````make dep```` installs all dependencies using apt-get (you will need the SDL2 libraries and a C++ compiler to compile)
4. ````make```` builds the program
5. ````./plunder```` runs the program

#### notes

* this program is still a work in progress
	* functional parts: Hoard Loot, Spell Scrolls, Spellbooks
	* being built/not yet functional : Other Tools
* there are ways to get this running in Windows and macOS but I haven't tested it yet - you just need the SDL2 libraries and a C++ compiler pretty much
* running **plunder** within a virtual machine will not use vsync correctly, and some screens may fly by at an alarming rate. This is to be expected in a vm but shouldn't effect core functionality. I'll cap frame rate at some point.
* tried to focus on things that WotC didn't provide good tools for in its latest online tool suite

#### continual development
I am making this program for myself and will continually update it as I see fit. Open source contributions are welcome.

*Anyone out there that uses this - please notify me of any issues!*
