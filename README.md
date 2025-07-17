<h1>DeepSeek AI with ESP8266 (Using Free OpenRouter API)</h1>
<p>Integrate AI-powered responses into your ESP8266 projects using the DeepSeek model via OpenRouter API (Free version).</p>

<h2>📌 Features</h2>
<ul>
  <li>✔ Connects ESP8266 to Wi-Fi and OpenRouter API</li>
  <li>✔ Sends user queries via Serial Monitor</li>
  <li>✔ Receives AI-generated responses in real-time</li>
  <li>✔ Handles HTTPS requests securely</li>
  <li>✔ Cleans and parses JSON response using ArduinoJson</li>
</ul>

<h2>🛠 Hardware Requirements</h2>
<ul>
  <li>ESP8266 NodeMCU or compatible board</li>
  <li>USB Cable</li>
  <li>Wi-Fi Network</li>
</ul>

<h2>⚙ Software Requirements</h2>
<ul>
  <li>Arduino IDE (with ESP8266 core installed)</li>
  <li>Arduino Libraries:
    <ul>
      <li>ESP8266WiFi.h</li>
      <li>WiFiClientSecure.h</li>
      <li>ArduinoJson.h</li>
    </ul>
  </li>
</ul>

<h2>🔑 Get Your Free API Key</h2>
<ol>
  <li>Visit <a href="https://openrouter.ai/">OpenRouter</a></li>
  <li>Sign up and generate your API Key</li>
  <li>Use a free DeepSeek model, for example:
    <pre><code>deepseek/deepseek-r1-0528:free</code></pre>
  </li>
</ol>

<h2>📂 Project Setup</h2>
<ol>
  <li>Clone this repository
    <pre><code>https://github.com/jitendrasharma-eng/DeepSeek-AI-with-ESP8266-Using-Free-OpenRouter-API-</code></pre>
  </li>
  <li>Open the .ino file in Arduino IDE</li>
  <li>Install required libraries
    <p>Go to Sketch → Include Library → Manage Libraries</p>
    <p>Install ArduinoJson</p>
  </li>
  <li>Edit Wi-Fi Credentials & API Key in code
    <pre><code>const char* ssid = "Your-WiFi-SSID";
const char* password = "Your-WiFi-Password";
const char* apiKey = "Your-OpenRouter-API-Key";</code></pre>
  </li>
</ol>

<h2>▶ How It Works</h2>
<ol>
  <li>ESP8266 connects to Wi-Fi</li>
  <li>Sends HTTPS POST request to OpenRouter API</li>
  <li>AI processes the query and returns response</li>
  <li>Serial Monitor displays AI answer</li>
</ol>

<h2>💻 Code Snippet</h2>
<pre><code>doc["model"] = "deepseek/deepseek-r1-0528:free";</code></pre>
<p>Change this if the model is unavailable:</p>
<ul>
  <li>deepseek/deepseek-chat:free</li>
  <li>deepseek/deepseek-lite:free</li>
</ul>

<h2>📸 Architecture</h2>
<pre><code>[ESP8266] → [Wi-Fi] → [OpenRouter API] → [DeepSeek Model] → Response on Serial Monitor</code></pre>

<h2>📺 Demo</h2>
<p>(Add a GIF or screenshot showing ESP8266 Serial Monitor with AI responses)</p>

<h2>🚀 Future Improvements</h2>
<ul>
  <li>✔ Display responses on OLED or LCD</li>
  <li>✔ Add Voice Input with AI response</li>
  <li>✔ Use for Smart IoT Assistant</li>
</ul>

<h2>📎 Full Tutorial</h2>
<p>👉 <a href="#">Read Complete .......</a></p>
