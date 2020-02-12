# `_BotInfo` File

If you are not familiar with options, place the file at the directory of `main.cpp`, or just outside the directory where the executable is.

`_BotInfo` file determines
* which bot your program is going to use,
* which server your program is going to connect,
* which configuration(Debug, Log, None) your program is going to use,
* which prefix you are going to use,
* and who will be the admin.

You may change the name of the file if you want with the option `-f 'FileDir'`.

## How to write the file

Please keep in mind that **the file should be written in LF**.

There are 5 options : `AdminID`, `BotToken`, `Config`, `Prefix`, and `ServerID`.
Each denotes what they mean.

You may set `BotToken` like :
```
BotToken = (Token of your bot);
```
Note that the semicolon at the end is necessary.

Other options can be written similarly. 