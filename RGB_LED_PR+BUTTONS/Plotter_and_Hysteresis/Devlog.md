# Dev Log – RGB LED Hysteresis + Serial Plotter Experiment

**Date:** 10–11 October

---
## Experimentation & Iteration

### Setup & Early Tests
- Wired RGB LED to PWM pins and photoresistor to A0.
- Initial test: blue leg only, verified flicker behavior.
- Observed initial hardware cutoff (~128 PWM).

### Serial Input Integration
- Tested storing red/green brightness via Serial input — values confirmed correct.
- Adjusted loop timing and delay placement to avoid missed reads.

### Smoothing & Hysteresis
- Implemented `averageSensorValue = (current + last)/2` for smoother output.
- Defined discrete ranges for red/green activation (`redON`/`greenON`) — introduced buffer zones for clean transitions.
- Adjusted scaling for Serial Plotter visualization: red ×100, green ×500 to match sensor value ranges.

### Debugging Highlights
- Rewiring made RGB PWM functionality possible.
- Rewiring reduced flicker and interference.
- PWM on common anode caused unexpected behavior; reverted to GND-based common cathode.
- Legacy `if(level<0)` checks for red/green disrupted output, deactivated as comment removed for future reference.
- Verified Serial Plotter output; curves show sensor vs. LED response.

### Observations
- Averaging stabilizes sensor-driven LED transitions.
- LED brightness still non-linear due to physical cutoff — “smooth” control limited.
- Serial + sensor timing coordination is critical for stable feedback loops.

---
## Lessons & Next Steps
- Consider multi-sample moving average for smoother hysteresis.
- Explore dynamic threshold definition for red/green activation.
- Reintroduce buttons for manual override/mode switching.
- Plan to merge into main RGB input project after refining smoothing and PWM handling.
