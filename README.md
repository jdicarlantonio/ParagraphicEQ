# ParagraphicEQ

ParagraphicEQ is a simple four-band paragraphic equalizer VST plugin for windows and linux. It uses the biquad design from http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt.


## How It Works

Using this plugin is very simple. There are a total of eight knobs - four knobs are used to set frequencies, and the other four control the the gain in dB. The Q Factor is proportional to the amount of gain. Basically, the Q Factor is equal to the amount of gain times a constant value which is universal across all bands. This constant is a value between 0 and 1, and it is decided by the user with the slider labeled "Q Proportion".

![ScreenShot](https://raw.github.com/jdicarlantonio/ParagraphicEQ/master/PEQScreenShot.png)
