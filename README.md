#gClock

##Documentation
###Installation
You can compile the project with :
```sh
cd gClock
./configure
make
sudo make install
```
###Running
This program needs a root access to interact with the GPIO pins.
Thus, you can run it using :
```sh
sudo gclock
```
You can edit the configuration file `/etc/gclock.conf` to change the alarm time and ringtone.
Simply use the format :
```
08:00			#hh:mm -> the alarm time
/path/to/audio/file	#The absolute location of the sound you want to be woken up by!
```
(Note: For now, the alarm is disabled as I'm trying to find a library to play sound in C. Any ideas?)

##Questions, Ideas
Feel free to open an issue, or email me at guillaume.ricard@mail.com
