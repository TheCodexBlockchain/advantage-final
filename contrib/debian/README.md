
Debian
====================
This directory contains files used to package advantaged/advantage-qt
for Debian-based Linux systems. If you compile advantaged/advantage-qt yourself, there are some useful files here.

## pivx: URI support ##


advantage-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install advantage-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your advantage-qt binary to `/usr/bin`
and the `../../share/pixmaps/pivx128.png` to `/usr/share/pixmaps`

advantage-qt.protocol (KDE)

