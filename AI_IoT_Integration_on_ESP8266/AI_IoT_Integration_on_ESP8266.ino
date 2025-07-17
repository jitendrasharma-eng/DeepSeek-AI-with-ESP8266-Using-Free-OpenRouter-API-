//DeepSeek AI with ESP8266 By Free API
//(Raw Response with cleaning)
//First of all generate free api from  OpenRouter website API used different deepseek free model if given model not responding
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// WiFi Credentials
const char* ssid = "espioT";       // WiFi SSID remains unchanged
const char* password = "1234_ioT";   // WiFi password remains unchanged

// OpenRouter API Key
const char* apiKey = "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";  // API key remains unchanged

// OpenRouter API Endpoint
const char* server = "openrouter.ai";   // OpenRouter's API server
const char* endpoint = "/api/v1/chat/completions";  // Correct API endpoint
const int port = 443;  // HTTPS port

WiFiClientSecure client;

void setup() {
  Serial.begin(115200);
  Serial.println("\nStarting...");

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  // Use insecure connection (not recommended for production)
  client.setInsecure();

  Serial.println("Enter your message for AI:");
}

void loop() {
  if (Serial.available()) {
    String userInput = Serial.readStringUntil('\n');  // Read user input from Serial Monitor
    userInput.trim();  // Remove extra spaces or newlines

    if (userInput.length() > 0) {
      Serial.println("Sending: " + userInput);
      askOpenRouterAI(userInput);  // Call function with user input
    }
  }
}

void askOpenRouterAI(String question) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi Disconnected! Reconnecting...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.print(".");
    }
    Serial.println("\nReconnected to WiFi!");
  }

  if (!client.connect(server, port)) {
    Serial.println("Connection to OpenRouter API failed!");
    return;
  }

  // Create JSON request
  DynamicJsonDocument doc(512);
  doc["model"] = "deepseek/deepseek-r1-0528:free";  // Use a valid model from OpenRouter
  JsonArray messages = doc.createNestedArray("messages");
  JsonObject systemMessage = messages.createNestedObject();
  systemMessage["role"] = "system";
  systemMessage["content"] = "You are a helpful assistant.";
  JsonObject userMessage = messages.createNestedObject();
  userMessage["role"] = "user";
  userMessage["content"] = question;

  String payload;
  serializeJson(doc, payload);

  // Debug: Print the payload
  Serial.println("Sending Payload:");
  Serial.println(payload);

  // Send HTTP Request
  client.println("POST " + String(endpoint) + " HTTP/1.1");
  client.println("Host: " + String(server));
  client.println("Authorization: Bearer " + String(apiKey));
  client.println("Content-Type: application/json");
  client.println("Content-Length: " + String(payload.length()));
  client.println();
  client.println(payload);

  // Wait for response
  while (client.connected() && !client.available()) {
    delay(10);
  }

  // Read response headers
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;  // End of headers
    }
  }

  // Read and clean the raw response
  String response = client.readString();
  client.stop();

//Serial.println("Raw Response:");
//Serial.println(response);

  // Clean the response by removing any non-JSON characters
  int startIdx = response.indexOf("{");
  int endIdx = response.lastIndexOf("}");
  if (startIdx != -1 && endIdx != -1) {
    response = response.substring(startIdx, endIdx + 1);
  }

  Serial.println("Cleaned Response:");
  Serial.println(response);

  // Parse JSON response
  DynamicJsonDocument jsonDoc(2048);  // Increase size if needed
  DeserializationError error = deserializeJson(jsonDoc, response);

  if (error) {
    Serial.println("Failed to parse JSON response: " + String(error.c_str()));
    return;
  }

  // Extract only the AI reply from the response
  if (jsonDoc.containsKey("choices") && jsonDoc["choices"].is<JsonArray>() && jsonDoc["choices"].size() > 0) {
    String aiReply = jsonDoc["choices"][0]["message"]["content"].as<String>();
    Serial.println("AI Response: " + aiReply);

   
  } else {
    Serial.println("No valid response from OpenRouter API.");
  }
}

