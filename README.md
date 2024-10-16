<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>Arduino Doorbell Project</h1>

<p>This project is a doorbell system using an Arduino. It features a button that, when pressed, sends a signal to play a sound via a speaker.</p>

<h2>Features</h2>
<ul>
    <li><strong>Button Press</strong>: The doorbell is activated by a pushbutton switch.</li>
    <li><strong>Audio Output</strong>: Plays a pre-defined song using a buzzer.</li>
    <li><strong>Wireless Communication</strong>: Uses RF modules for wireless data transmission.</li>
</ul>

<h2>Components Required</h2>

<h3>Transmitter</h3>
<ul>
    <li>Arduino Nano or compatible board</li>
    <li>433 MHz RF Transmitter Module</li>
    <li>Copper wire 0.7mm</li>
    <li>Pushbutton switch</li>
    <li>9V battery or appropriate power supply</li>
    <li>9V clip-on battery connector without barrel jack</li>
    <li>Jumper wires</li>
    <li>Breadboard</li>
</ul>

<h3>Receiver</h3>
<ul>
    <li>Arduino Nano or compatible board</li>
    <li>433 MHz RF Receiver Module</li>
    <li>Copper wire 0.7mm</li>
    <li>Buzzer</li>
    <li>9V battery or appropriate power supply</li>
    <li>9V clip-on battery connector without barrel jack</li>
    <li>Jumper wires</li>
    <li>Breadboard</li>
</ul>

<h2>Important Notes</h2>
<ol>
    <li><strong>RadioHead Library</strong>: Both the transmitter and receiver use the <a href="https://www.airspayce.com/mikem/arduino/RadioHead/">RadioHead</a> library for wireless communication. Ensure that the library is installed and properly referenced in your Arduino code.</li>
    <li><strong>Antenna Amplification</strong>: To increase the transmission and reception range of the RF modules, a simple copper wire can be used as an antenna. This greatly enhances the signal strength. For more details on how to do this, refer to this <a href="https://www.youtube.com/watch?v=8iDfd6TxcgI" target="_blank">video tutorial</a>.</li>
</ol>

<h2>Transmitter Schematic</h2>
<p>Below is the schematic for the transmitter part of the project:</p>
<img src="transmitter/transmitter_schematic.png" alt="Transmitter Schematic" width="600">

<h2>Receiver Schematic</h2>
<p>Below is the schematic for the receiver part of the project:</p>
<img src="receiver/receiver_schematic.png" alt="Receiver Schematic" width="600">

</body>
</html>
