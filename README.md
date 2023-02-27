# Clean Machine

**Clean Machine**, by Amalgamated Signals, is a dynamics controller with features of both a saturator and a compressor. It has timing controls like a compressor, but it applies a continuous gain reduction curve like a saturator. It also has a third timing parameter called “transition”, to control the speed of the shift between attack and release modes, for more transparent control of dynamics.

At very fast settings and relatively low drive, Clean Machine acts like a saturator, subtly thickening the sound and gluing mix elements together. Slightly increase the attack and release times for gentler transient control and reduced harmonic distortion.

With higher levels of drive, Clean Machine can control large dynamic swings and peaks. Try a fast attack with a slow release, and notice how the compression sounds more transparent as you increase the transition time.

Screenshot of Clean Machine

<img src="https://amalgamatedsignals.com/clean-machine.png" width=60% height=60%>

### Buy and download

You can choose how much you want to pay for Clean Machine. There are no restrictions on downloads or usage.

[Buy Clean Machine](https://amalgamatedsignals.com/buy/clean-machine) for the amount it's worth to you. You can download it and try it out before paying.

Download Clean Machine [AU/VST for Mac](https://amalgamatedsignals.com/downloads/Clean%20Machine.dmg).

Download Clean Machine [VST for Windows](https://amalgamatedsignals.com/downloads/Clean%20Machine.zip).

Download Clean Machine [source code](https://amalgamatedsignals.com/downloads/clean-machine.zip).

### Controls and metering

Drive controls how far to push the input into the compression curve. More drive means more compression, with the ratio gradually curving from 1:1 to ∞:1. The units are decibels.

High pass controls a 6dB/octave high-pass filter on the sidechain. The units are hertz, specifying the frequency where the sensitivity of the compressor is reduced by 3dB. A higher frequency here means the compressor reacts less to bass.

**Attack** is the speed at which the compressor reacts to increases in level. The units are milliseconds.

**Release** is the speed at which the compressor reacts to decreases in level. The units are milliseconds.

**Transition** is the rate at which the compressor changes speed between attack and release. Clean Machine does not use a fixed attack or release time; rather, it uses the attack and release times as “targets” and is always in between the two of them, chasing one or the other. Transition time, specified in milliseconds, tells it how fast to chase.

At the fastest transition settings, the attack and release settings work as advertised: the compressor flips between distinct attack and release modes. As the transition time increases, these modes start to blur into one another. With a fast attack setting and a slow release, this allow transients to come through during the initial attack phase, followed by a quick initial release. The result is unobtrusive compression that adapts to the rhythm of the input signal.

**Mix** controls the relative mix of the compressed signal and the input. The units are percents. Clean Machine has an eventual compression ratio of ∞:1, and lower mix settings effectively reduce this ratio, for a more gentle compression curve. The gain reduction meter reflects gain reduction after mix is applied.

**Make up** controls how much gain to add to the output to compensate for compression. Make-up gain is applied after the mix stage. The units are decibels.

The **gain reduction** meter on the left shows much compression is happening. Each square represents one decibel.

The **heart** icon in the bottom right corner is a link to the payment page, to support Clean Machine development.
Help and bug reports

brian@amalgamatedsignals.com 
