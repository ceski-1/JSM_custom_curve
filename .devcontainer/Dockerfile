FROM ubuntu:24.04

# Build tools
RUN apt-get update && apt-get install -y \
	build-essential \
	cmake \
	ninja-build \
	pkg-config \
	gdb \
	git \
	&& apt-get clean

# Project dependencies
RUN apt-get update && apt-get install -y \
	libgtk-3-dev \
	libappindicator3-dev \
	libevdev-dev \
    libhidapi-dev \
	&& apt-get clean

# SDL3 dependencies
RUN apt-get update && apt-get install -y \
	gnome-desktop-testing libasound2-dev libpulse-dev \
	libaudio-dev libfribidi-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
	libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxtst-dev \
	libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
	libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev libthai-dev \
	libpipewire-0.3-dev libwayland-dev libdecor-0-dev liburing-dev \
	&& apt-get clean