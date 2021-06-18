# Why use-the AAT?
This is my most recent project utilizing my Arduino Photon. I wanted to use the biggest variaty of mathematics and hardware possible, it utilizes the a MicroOLED, a DHT22, a switch and a LED.

Temperature isn't always helpful for knowing how comfortable the climate will be. Humidity is also essential to determine comfort.
A metric that combines these is the AAT (Australian Apparent Temperature). It also conveniently allows me to use both my new tempature and humidity module.

The AAT quantifies how the air will feel based on both variables. 
AAT = Ta + 0.33•ρ−0.70•ws−4.00
AAT = the Apparent Temperature in °C;
Ta = the Dry bulb Temperature in °C;
ρ= rh•6.105•e(17.27*Ta/(237.7+Ta))is the water vapor pressure (hPa);
ws = the wind speed (m/s) at 10 meter above the ground;
rh = the Relative Humidity (%)

By default the MicroOLED display shows Humidity and Temp
The brightness of the LED reflects humidity. Off at 0%, full intensity at 100%
While the switch is held down, the display reflects AAT
