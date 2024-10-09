<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arduino Doorbell Project</title>
</head>
<body>

<h1>Arduino Doorbell Project</h1>

<p>This project is a simple doorbell system using an Arduino. It features a button that, when pressed, sends a signal to play a sound via a speaker. The system is designed to be low-power, utilizing sleep modes to conserve battery life.</p>

<h2>Features</h2>
<ul>
    <li><strong>Button Press</strong>: The doorbell is activated by a pushbutton switch.</li>
    <li><strong>Audio Output</strong>: Plays a pre-defined song using a passive buzzer or piezoelectric speaker.</li>
    <li><strong>Low Power Consumption</strong>: Implements power-saving techniques by using idle and power-down modes.</li>
    <li><strong>Wireless Communication</strong>: Uses the RadioHead ASK library for wireless data transmission.</li>
</ul>

<h2>Components Required</h2>
<ul>
    <li>Arduino Nano or compatible board</li>
    <li>Passive Buzzer or Piezoelectric Speaker</li>
    <li>Pushbutton switch</li>
    <li>Resistor (10kΩ for pull-down)</li>
    <li>9V battery or appropriate power supply</li>
    <li>Jumper wires</li>
    <li>Breadboard</li>
</ul>

<h2>Wiring Diagram</h2>
<img src="path/to/your/wiring_diagram.png" alt="Wiring Diagram" /> <!-- Replace with your actual wiring diagram -->

<h2>Code</h2>
<p>The code utilizes the <code>RH_ASK</code> library for handling communication and the <code>LowPower</code> library for power management. Below is a brief explanation of the main sections of the code.</p>

<h3>Setup</h3>
<pre><code>
void setup() {
  Serial.begin(9600);
  if (!driver.init()) {
    Serial.println("init failed");
  }
}
</code></pre>

<h3>Loop</h3>
<pre><code>
void loop() {
  uint8_t buf[1];   // Buffer for incoming data
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen) && buf[0] == 'a') {
    Serial.println("Playing song");  
    play_song(hpLength, hp, hpDurations, hpTempo);
    Serial.println("Finished playing song");
  } else {
    // Enter Idle mode to save power
    LowPower.idle(SLEEP_1S, ADC_OFF, TIMER2_ON, TIMER1_ON, TIMER0_ON, SPI_ON);
  }
}
</code></pre>

<h2>Installation</h2>
<ol>
    <li>Clone this repository to your local machine.</li>
    <pre><code>git clone https://github.com/yourusername/arduino-doorbell.git</code></pre>
    <li>Install the required libraries:
        <ul>
            <li><a href="http://www.airspayce.com/mikem/arduino/RadioHead/">RadioHead Library</a></li>
            <li><a href="https://github.com/rocketscream/Low-Power">LowPower Library</a></li>
        </ul>
    </li>
    <li>Upload the code to your Arduino using the Arduino IDE.</li>
</ol>

<h2>Usage</h2>
<p>Press the button connected to the Arduino to send a signal and play the doorbell sound.</p>

<h2>License</h2>
<p>This project is licensed under the MIT License - see the <a href="LICENSE">LICENSE</a> file for details.</p>

<h2>Acknowledgments</h2>
<ul>
    <li>Inspired by the Arduino community and tutorials on building interactive projects.</li>
    <li>Thank you to the developers of the <code>RH_ASK</code> and <code>LowPower</code> libraries.</li>
</ul>

</body>
</html>
